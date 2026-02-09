Perfect. This is exactly the right moment to switch from *architecture* to *execution without panic*.

Below is a **strict, step-by-step checklist**.
If you follow it **in order**, you will *never* feel lost, and every step will compile and make sense.

No clever jumps. No “I’ll fix it later”.

---

# PIPEX IMPLEMENTATION CHECKLIST

*(Unix-correct, minishell-ready)*

---

## PHASE 0 — Ground rules (do this first)

☑ Decide these **now**, don’t revisit later:

* `execve()` **only called in child**
* `exec_cmd()` **never returns on success**
* Parent returns **last command exit status**
* `errno` → shell exit codes (`126`, `127`)
* Commands never open files
* Parsing never forks

Once fixed → no confusion later.

---

## PHASE 1 — Error system (no pipes yet)

**Goal:** centralize exit codes and messages.

### Implement:

* `error.h`
* `error_exit()`
* `error_return()`
* `shell_exit_code_from_errno()`

### Verify:

* `ENOENT` → `127`
* `EACCES`, `EISDIR` → `126`
* Others → `1`

☑ Test with dummy calls from `main`.
 
---

## PHASE 2 — Utility layer (no fork, no exec)

**Goal:** pure helpers that can’t break runtime.

### Implement:

* `split_cmd()`
* `free_split()`
* `resolve_path()`

### Rules:

* `resolve_path()` returns `NULL` on failure
* No printing
* No exit

☑ Test:

* `"ls"` resolves
* `"nonexistent"` returns NULL
* Absolute paths pass through

---

## PHASE 3 — Command object (`t_cmd`)

**Goal:** one command = one struct.

### Implement:

* `cmd_create()`
* `cmd_destroy()`

### `cmd_create()` must:

* split cmd string
* resolve path
* **not open files**
* **not fork**
* return NULL on error

☑ Test:

* Create + destroy without leaks
* Path resolution correct
* argv correctly NULL-terminated

---

## PHASE 4 — `exec_cmd()` (child-only)

**Goal:** single responsibility execution.

### Implement:

* `exec_cmd()`

### Must:


* close unused FDs
* call `execve()`
* on failure:

  * detect errno
  * print shell-style error
  * exit with `126/127/1`

☑ Test:

* Call it directly in `main` with fork
* Confirm exit code correctness

---

## PHASE 5 — I/O handling (still no pipeline)

**Goal:** isolate file & heredoc logic.

### Implement:

* `open_infile()`
* `open_outfile()`
* `heredoc_read()`
* `setup_input_fd()`
* `setup_output_fd()`

### Rules:

* Errors go through `error_exit()`
* `heredoc_read()` returns a readable FD

☑ Test:

* infile read
* outfile truncate/append
* heredoc pipe works standalone

---

## PHASE 6 — Parsing logic

**Goal:** convert argv → pipeline data.

### Implement:

* `detect_input_type()`
* `parse_pipeline()`

### `parse_pipeline()` must:

* detect heredoc vs infile
* open initial input fd
* open final output fd
* create `t_cmd` array
* assign `in_fd` / `out_fd` **only for first/last**

☑ Test:

* print parsed structure
* no fork yet
* correct command count

---

## PHASE 7 — Pipeline structure

**Goal:** prepare execution container.

### Implement:

* `pipeline_create()`
* `pipeline_destroy()`

### Must:

* allocate cmds array
* allocate pid array
* own memory cleanly

☑ Test:

* create + destroy with no execution

---

## PHASE 8 — Pipeline execution (core logic)

**Goal:** actual Unix pipe behavior.

### Implement:

* `pipeline_execute()`

### Loop rules:

* For each command:

  * create pipe (except last)
  * fork
  * child:

    * set input fd
    * set output fd
	* `dup2(cmd->in_fd, STDIN)`
	* `dup2(cmd->out_fd, STDOUT)`
    * exec_cmd()
  * parent:

    * close used fds
    * store pid

### After loop:

* waitpid(last_pid)
* wait remaining children
* return last exit status

☑ Test:

* 2 commands
* 3 commands
* heredoc
* error cases

---

## PHASE 9 — `pipex()` entry point

**Goal:** glue everything cleanly.

### Implement:

* `pipex()`

### Must:

* validate argc
* call parser
* call pipeline_execute
* cleanup
* return exit status

☑ Test:

* valid usage
* invalid usage
* compare with bash output

---

## PHASE 10 — Final validation

Run these **without debugging**:

```sh
./pipex infile "cat" "grep a" outfile
./pipex infile "noncmd" "cat" outfile
./pipex infile "ls" "wc -l" outfile
./pipex here_doc EOF "cat" "wc" outfile
```

Check:

* exit codes
* stderr messages
* no fd leaks
* no zombies

---

## Mental rule (this saves you)

If you ever feel lost, ask:

> “Is this parsing, environment setup, or execution?”

If you can’t answer — you’re mixing layers.

---

If you want next:

* minishell mapping checklist
* signal handling prep
* builtin vs external command split
* or “what NOT to abstract yet”

You’re doing this the right way.
