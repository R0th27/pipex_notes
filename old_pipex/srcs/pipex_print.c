/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:08:39 by htoe              #+#    #+#             */
/*   Updated: 2026/02/09 19:17:07 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_print(t_cmd *cmd)
{
	int	i;

	if (!cmd)
		return ;
	i = -1;
	while (cmd->argv[++i])
		printf("%s\n", cmd->argv[i]);
	printf("path: %s\n", cmd->path);
	printf("in_fd: %d\n", cmd->in_fd);
	printf("out_fd: %d\n", cmd->out_fd);
}

void	pipeline_print(t_pipeline *pl)
{
	int	i;

	printf("cmd_counts: %d\n", pl->cmd_counts);
	i = -1;
	while (++i < pl->cmd_counts)
	{
		printf("[%d]\n", i);
		cmd_print(pl->cmds[i]);
	}
}
