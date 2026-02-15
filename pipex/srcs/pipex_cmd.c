/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 01:38:23 by htoe              #+#    #+#             */
/*   Updated: 2026/02/15 20:29:22 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	*cmd_create(char *cmd_str, char **dirs)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->in_fd = -1;
	cmd->out_fd = -1;
	cmd->paths = NULL;
	cmd->argv = ft_split(cmd_str, ' ');
	if (!cmd -> argv || !cmd->argv[0])
		return (cmd_destroy(&cmd), NULL);
	cmd->paths = paths_builder(cmd->argv[0], dirs);
	return (cmd);
}

int	exec_cmd(t_cmd *cmd, char **envp)
{
	int	i;
	int	saw_eacces;
	int	saved_errno;

	saw_eacces = 0;
	saved_errno = 0;
	i = 0;
	while (cmd->paths[i])
	{
		execve(cmd->paths[i], cmd->argv, envp);
		if (errno == EACCES)
			saw_eacces = 1;
		else if (errno != ENOENT && !saved_errno)
			saved_errno = errno;
		i++;
	}
	if (i == 1 && errno == ENOENT)
		return (error_perror(cmd->argv[0]), errno);
	if (!saved_errno && !saw_eacces)
		return (error_cmd_not_found(cmd->argv[0]), ENOENT);
	if (saw_eacces)
		errno = EACCES;
	else if (saved_errno)
		errno = saved_errno;
	return (error_perror(cmd->argv[0]), errno);
}
