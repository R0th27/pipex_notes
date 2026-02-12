/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 04:52:57 by htoe              #+#    #+#             */
/*   Updated: 2026/02/10 08:51:42 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_cmd.h"
#include "libft.h"
#include "pipex_utils.h"
#include "pipex_error.h"
#include "pipex_paths.h"
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

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

void	cmd_destroy(t_cmd **cmd)
{
	if (!*cmd)
		return ;
	free_split((*cmd)->argv);
	free_split((*cmd)->paths);
	free(*cmd);
	*cmd = NULL;
}

t_error	exec_cmd(t_cmd **cmd, char **envp)
{
	int	i;
	int	file_exist;

	if (!(*cmd)->paths)
	{
		error_command_not_found((*cmd)->argv[0]);
		return (ERR_CMD_NOT_FOUND);
	}
	file_exist = 0;
	i = 0;
	while ((*cmd)->paths[i] && !file_exist)
	{
		execve((*cmd)->paths[i], (*cmd)->argv, envp);
		if (errno == EACCES || errno == EISDIR || errno == ENOEXEC)
			file_exist = 1;
		else
			i++;
	}
	error_perror((*cmd)->argv[0]);
	return (ERR_EXEC);
}
