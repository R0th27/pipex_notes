# 1️⃣ Public API — `pipex.h`

This is the **only header `main.c` needs**.

```c
#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

/*
** Entry point
** Returns the shell-compatible exit status
*/
int pipex(int ac, char **av, char **envp);

#endif
```

Rule:

* `main.c` knows **nothing** about pipes, forks, parsing, exec
* It delegates everything

---

# 2️⃣ Error model — `error.h`

This matches **POSIX shell behavior**, not just pipex rules.

```c
#ifndef ERROR_H
# define ERROR_H

# include <errno.h>

/*
** High-level error categories
*/
typedef enum e_error
{
    ERR_OK,

    /* usage / parsing */
    ERR_USAGE,

    /* system failures */
    ERR_PIPE,
    ERR_FORK,
    ERR_MALLOC,
    ERR_DUP,

    /* file-related (input/output) */
    ERR_INFILE,
    ERR_OUTFILE,

    /* command-related */
    ERR_CMD_NOT_FOUND,   // ENOENT
    ERR_CMD_NO_EXEC,    // EACCES
    ERR_CMD_IS_DIR,     // EISDIR

    /* execve failed after fork */
    ERR_EXEC
}   t_error;

/*
** Error handling
*/
void    error_exit(t_error err, const char *target);
int     error_return(t_error err, const char *target);

/*
** errno → shell exit code mapping
*/
int     shell_exit_code_from_errno(int err);

#endif
```

Shell truth:

* `126` → found but not executable / is directory
* `127` → command not found
* others → `1`

---

# 3️⃣ Command domain — `cmd.h`

This **survives into minishell almost unchanged**.

```c
#ifndef CMD_H
# define CMD_H

# include <unistd.h>

typedef struct s_cmd
{
    char    **argv;     // argv passed to execve
    char    *path;      // resolved executable path
    int     in_fd;      // stdin for this command
    int     out_fd;     // stdout for this command
}   t_cmd;

/*
** Lifecycle
*/
t_cmd   *cmd_create(char *cmd_str, char **envp);
void    cmd_destroy(t_cmd *cmd);

/*
** Execution
*/
void    exec_cmd(t_cmd *cmd, char **envp);

#endif
```

Rules:

* `t_cmd` owns everything inside it
* `exec_cmd()` **never returns** on success
* On failure → prints error → exits with shell code

---


# 5️⃣ I/O & heredoc domain — `io.h`

Shell responsibility, **not command responsibility**.

```c
#ifndef IO_H
# define IO_H

typedef enum e_input_type
{
    INPUT_FILE,
    INPUT_HEREDOC
}   t_input_type;

/*
** Files
*/
int open_infile(const char *path);
int open_outfile(const char *path, int append);

/*
** Heredoc
*/
int heredoc_read(const char *limiter);

/*
** FD setup helpers
*/
int setup_input_fd(t_input_type type, const char *arg);
int setup_output_fd(const char *arg, int append);

#endif
```

Rules:

* Commands never open files
* They only **receive FDs**

---


# 4️⃣ Pipeline domain — `pipeline.h`

Handles **N commands**, pipes, forks, waits.

```c
#ifndef PIPELINE_H
# define PIPELINE_H

# include <sys/types.h>
# include "cmd.h"

typedef struct s_pipeline
{
    t_cmd   **cmds;     // array of commands
    int     cmd_count;
    pid_t   *pids;      // child PIDs (size = cmd_count)
}   t_pipeline;

/*
** Lifecycle
*/
t_pipeline *pipeline_create(int cmd_count);
void        pipeline_destroy(t_pipeline *pl);

/*
** Execution
*/
int         pipeline_execute(t_pipeline *pl, char **envp);

#endif
```

Rules:

* Pipeline owns:

  * pipes
  * forks
  * wait logic
* Returns **last command exit status only**

---

# 6️⃣ Parsing / argument interpretation — `parse.h`

Pipex parsing is dumb on purpose.
Minishell replaces this later.

```c
#ifndef PARSE_H
# define PARSE_H

# include "pipeline.h"
# include "io.h"

/*
** Detect input mode
*/
t_input_type detect_input_type(const char *arg);

/*
** Build pipeline from argv
*/
t_pipeline *parse_pipeline(
                int ac,
                char **av,
                char **envp,
                int *in_fd,
                int *out_fd
            );

#endif
```

Responsibilities:

* decide heredoc vs infile
* count commands
* create `t_cmd` objects
* assign initial FDs

---

# 7️⃣ Path & utilities — `utils.h`

No exec, no fork, no pipe here.

```c
#ifndef UTILS_H
# define UTILS_H

/*
** Path resolution
*/
char    *resolve_path(const char *cmd, char **envp);

/*
** String helpers
*/
char    **split_cmd(const char *cmd_str);

/*
** Memory helpers
*/
void    free_split(char **arr);

#endif
```

Rules:

* `resolve_path()`:

  * returns malloc’d string or NULL
  * never prints errors

---

# 8️⃣ Execution flow (conceptual)

This is how **real Unix shells think**:

```
main
 └── pipex
      ├── parse_pipeline
      │    ├── detect_input_type
      │    ├── heredoc / infile
      │    ├── cmd_create (N times)
      │
      ├── pipeline_execute
      │    ├── pipe
      │    ├── fork
      │    ├── dup2
      │    ├── exec_cmd
      │    └── waitpid (last cmd)
      │
      └── cleanup & return exit status
```

---

# 9️⃣ Why THIS is “the actual design”

Because:

* Commands are **data**
* Pipelines are **execution strategy**
* I/O is **environment setup**
* Errors are **centralized**
* Exit codes are **shell-correct**
* Nothing depends on argv structure directly except parsing

This is:

* how `bash` thinks
* how `zsh` thinks
* how minishell *must* think

---

If you want next:

* I can give you a **checklist order** to implement this cleanly
* Or a **minimal stub version** (empty functions, compiles)
* Or a **mapping from this → minishell structs**

But for now — this is the real map.
