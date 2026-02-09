t_error init_exec(t_exec *ctx, int ac, char **av, char **envp)
{
    ctx->args.argc = ac;
    ctx->args.argv = av;
    ctx->args.envp = envp;

    ctx->ctrl.state = ST_INIT;
    ctx->ctrl.error = ERR_OK;

    ctx->io.infile_fd = -1;
    ctx->io.outfile_fd = -1;
    ctx->proc.pid1 = -1;
    ctx->proc.pid2 = -1;

    return (ERR_OK);
}

int main(int ac, char **av, char **envp)
{
    t_exec ctx;

    if (init_exec(&ctx, ac, av, envp) != ERR_OK)
        return (1);

    run_pipex(&ctx);
    cleanup_exec(&ctx);
    return (0);
}

args.h        // parsing & validation
io.h          // files, pipes, heredoc
proc.h        // fork/exec/wait
error.h       // error enums & helpers
state.h       // execution states
pipex.h       // public glue

// error.h
typedef enum e_error {
    ERR_OK,
    ERR_MALLOC,
    ERR_FORK,
    ERR_EXEC
} t_error;

void    handle_error(t_error err);

#ifndef PIPEX_H
# define PIPEX_H

# include "args.h"
# include "io.h"
# include "proc.h"
# include "error.h"
# include "state.h"

typedef struct s_exec {
    t_args  args;
    t_io    io;
    t_proc  proc;
    t_ctrl  ctrl;
} t_exec;

int pipex(int ac, char **av, char **envp);

#endif


typedef struct s_args {
    int     argc;
    char  **argv;
    char  **envp;
} t_args;


typedef struct s_io {
    int     infile_fd;
    int     outfile_fd;
    int     pipe_fd[2];
    t_type  input_type;
} t_io;

typedef struct s_proc {
    pid_t   pid1;
    pid_t   pid2;
} t_proc;
;

typedef struct s_ctrl {
    t_state state;
    t_error error;
} t_ctrl;

typedef struct s_exec {
    t_args  args;
    t_io    io;
    t_proc  proc;
    t_ctrl  ctrl;
} t_exec;
