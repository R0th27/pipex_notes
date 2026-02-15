/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 23:10:48 by htoe              #+#    #+#             */
/*   Updated: 2026/02/15 08:00:02 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "pipex_types.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

//utils
t_input_type	detect_input_type(const char *arg);
void			free_split(char **arr);

//exec
int				fork_pipeline(t_pipeline *pl, char **envp);
void			close_all_fds(t_pipeline *pl);

//parse
t_error			parse_pipeline(int argc, char **argv, char **envp,
					t_pipeline **pl);

//pipeline
t_pipeline		*pipeline_create(int cmd_count);
int				pipeline_fill_cmds(t_pipeline *pl, char **argv, char **envp);
void			pipeline_assign_endpoints(t_pipeline *pl, int in_fd,
					int out_fd);
void			pipeline_destroy(t_pipeline **pl);
void			pipe_link(t_pipeline *pl);
int				pipe_construct(t_pipeline **pl);

//paths
char			**paths_builder(char *cmd_str, char **dirs);
char			**extract_path_dirs(char **envp);

//cmd
t_cmd			*cmd_create(char *cmd_str, char **dirs);
void			cmd_destroy(t_cmd **cmd);
int				exec_cmd(t_cmd *cmd, char **envp);

//IO
int				heredoc_read(int fd, const char *limiter);
int				setup_input_fd(t_input_type type, const char *arg);
int				setup_output_fd(t_input_type type, const char *arg);
int				open_file_rdonly(const char *path);
int				open_file_append(const char *path);
int				open_file_trunc(const char *path);

//error
void			error_usage(void);
void			error_cmd_not_found(const char *cmd);
void			error_print(const char *target, const char *message);
void			error_perror(const char *target);
int				error_code_from_errno(int err);

//print
void			print_cmd(t_cmd *cmd);
void			print_pipeline(t_pipeline *pl);

#endif
