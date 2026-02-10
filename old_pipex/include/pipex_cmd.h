/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 04:37:49 by htoe              #+#    #+#             */
/*   Updated: 2026/02/08 07:50:40 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_CMD_H
# define PIPEX_CMD_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "pipex_utils.h"
# include "pipex_error.h"

typedef struct s_cmd
{
	char	**argv;
	char	*path;
	int		in_fd;
	int		out_fd;
}	t_cmd;

t_cmd	*cmd_create(char *cmd_str, char **envp);
void	cmd_destroy(t_cmd *cmd);
void	exec_cmd(t_cmd *cmd, char **envp);

#endif
