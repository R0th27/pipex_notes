/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_prints.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 03:22:35 by htoe              #+#    #+#             */
/*   Updated: 2026/02/15 03:54:16 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	print_cmd(t_cmd *cmd)
{
	int	i;

	printf("[argv] : ");
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
	while (i < pl->cmd_counts - 1)
	{
		printf("[%d][%d]", pl->pipefd[i][0], pl->pipefd[i][1]);
		if (i + 1 < pl->cmd_counts - 1)
			printf(" : ");
		i++;
	}
	printf("\n");
	i = 0;
	while (i < pl->cmd_counts)
	{
		printf("########## [%d] ##########\n", i);
		print_cmd(pl->cmds[i]);
		i++;
	}
}
