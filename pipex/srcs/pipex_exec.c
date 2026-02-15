/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 05:03:47 by htoe              #+#    #+#             */
/*   Updated: 2026/02/15 08:02:41 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_pipeline(int pos, t_pipeline *pl, char **envp)
{
	dup2(pl->cmds[pos]->in_fd, STDIN_FILENO);
	dup2(pl->cmds[pos]->out_fd, STDOUT_FILENO);
	close_all_fds(pl);
	return (exec_cmd(pl->cmds[pos], envp));
}

int	fork_pipeline(t_pipeline *pl, char **envp)
{
	int		status;
	int		pid;
	int		saved_errno;
	int		i;

	i = -1;
	while (++i < pl->cmd_counts)
	{
		pid = fork();
		if (pid == -1)
			return (error_perror("fork"), 1);
		if (pid == 0)
		{
			if (pl->cmds[i]->in_fd != -1 && pl->cmds[i]->out_fd != -1)
				saved_errno = exec_pipeline(i, pl, envp);
			else
			{
				saved_errno = EBADF;
				close_all_fds(pl);
			}
			pipeline_destroy(&pl);
			exit(error_code_from_errno(saved_errno));
		}
	}
	return (close_all_fds(pl), waitpid(pid, &status, 0), status >> 8);
}
