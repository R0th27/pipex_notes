/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 05:25:17 by htoe              #+#    #+#             */
/*   Updated: 2026/02/15 06:26:02 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipeline_destroy(t_pipeline **pl)
{
	int	i;

	if (!*pl)
		return ;
	if ((*pl)->cmds)
	{
		i = -1;
		while (++i < (*pl)->cmd_counts)
		{
			if ((*pl)->cmds[i])
				cmd_destroy(&((*pl)->cmds[i]));
		}
		free((*pl)->cmds);
	}
	if ((*pl)->pipefd)
		free((*pl)->pipefd);
	free(*pl);
	*pl = NULL;
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

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	close_all_fds(t_pipeline *pl)
{
	int	i;

	if (!pl)
		return ;
	i = 0;
	while (i < pl->cmd_counts)
	{
		close(pl->cmds[i]->in_fd);
		close(pl->cmds[i]->out_fd);
		i++;
	}
}
