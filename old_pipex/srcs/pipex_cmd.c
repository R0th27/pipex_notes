/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 04:40:15 by htoe              #+#    #+#             */
/*   Updated: 2026/02/09 18:59:00 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_cmd.h"

t_cmd	*cmd_create(char *cmd_str, char **envp)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd -> path = NULL;
	cmd -> argv = ft_split(cmd_str, ' ');
	if (!cmd -> argv || !cmd -> argv[0])
		return (cmd_destroy(cmd), error_return(ERR_MALLOC, NULL), NULL);
	cmd -> path = resolve_path(cmd -> argv[0], envp);
	cmd -> in_fd = -1;
	cmd -> out_fd = -1;
	return (cmd);
}

void	cmd_destroy(t_cmd *cmd)
{
	if (!cmd)
		return ;
	free_split(cmd -> argv);
	free(cmd -> path);
	free(cmd);
}

void	exec_cmd(t_cmd *cmd, char **envp)
{
	int	code;

	if (!cmd -> path)
	{
		errno = ENOENT;
		code = error_return(ERR_CMD_NOT_FOUND, cmd -> argv[0]);
		cmd_destroy(cmd);
		exit(code);
	}
	execve(cmd -> path, cmd -> argv, envp);
	code = error_return(ERR_EXEC, cmd -> argv[0]);
	cmd_destroy(cmd);
	exit(code);
}
