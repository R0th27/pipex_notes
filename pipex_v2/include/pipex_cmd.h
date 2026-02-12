/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 04:52:52 by htoe              #+#    #+#             */
/*   Updated: 2026/02/10 08:59:09 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_CMD_H
# define PIPEX_CMD_H

# include "pipex_error.h"

typedef struct s_cmd
{
	char	**argv;
	char	**paths;
	int		in_fd;
	int		out_fd;
}	t_cmd;

t_cmd	*cmd_create(char *cmd_str, char **envp);
void	cmd_destroy(t_cmd **cmd);
t_error	exec_cmd(t_cmd **cmd, char **envp);

#endif
