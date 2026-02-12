/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_prints.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 05:50:31 by htoe              #+#    #+#             */
/*   Updated: 2026/02/10 08:57:47 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_cmd.h"
#include "pipex_pipeline.h"
#include <stdio.h>

void	print_cmd(t_cmd *cmd)
{
	int	i;

	printf("[argv]\n");
	if (cmd -> argv)
	{
		i = -1;
		while (cmd->argv[++i])
			printf("[%s]", cmd->argv[i]);
	}
	else
		printf("<NILL>");
	printf("\n");
	printf("[paths]\n");
	if (cmd -> paths)
	{
		i = -1;
		while (cmd->paths[++i])
			printf("[%s]", cmd->paths[i]);
	}
	else
		printf("<NILL>");
	printf("\n");
	printf("[%d] : [%d]\n", cmd->in_fd, cmd->out_fd);
}

void	print_pipeline(t_pipeline *pl)
{
	int	i;

	printf("[CMD COUNT: %d]\n", pl->cmd_counts);
	i = 0;
	while (i < pl->cmd_counts)
	{
		printf("########## [%d] ##########\n", i);
		print_cmd(pl->cmds[i]);
		i++;
	}
}
