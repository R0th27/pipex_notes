/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 03:36:51 by htoe              #+#    #+#             */
/*   Updated: 2026/02/15 05:25:35 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipeline	*pipeline_create(int cmd_count)
{
	t_pipeline	*pl;

	pl = (t_pipeline *)malloc(sizeof(t_pipeline));
	if (!pl)
		return (NULL);
	pl->cmd_counts = cmd_count;
	pl->cmds = ft_calloc(cmd_count, sizeof(t_cmd *));
	if (!pl->cmds)
		return (pipeline_destroy(&pl), NULL);
	pl->pipefd = ft_calloc(cmd_count - 1, sizeof(int [2]));
	if (!pl->pipefd)
		return (pipeline_destroy(&pl), NULL);
	return (pl);
}

int	pipeline_fill_cmds(t_pipeline *pl, char **argv, char **envp)
{
	int		i;
	char	**dirs;

	dirs = extract_path_dirs(envp);
	i = -1;
	while (++i < pl->cmd_counts)
	{
		pl->cmds[i] = cmd_create(argv[i], dirs);
		if (!pl->cmds[i])
		{
			while (i > 0)
				cmd_destroy(&(pl->cmds[--i]));
			return (free_split(dirs), 0);
		}
	}
	free_split(dirs);
	return (1);
}

void	pipeline_assign_endpoints(t_pipeline *pl, int in_fd, int out_fd)
{
	pl->cmds[0]->in_fd = in_fd;
	pl->cmds[pl->cmd_counts - 1]->out_fd = out_fd;
}

int	pipe_construct(t_pipeline **pl)
{
	int	i;

	i = 0;
	while (i < ((*pl)->cmd_counts - 1))
	{
		if (pipe((*pl)->pipefd[i]) == -1)
		{
			while (--i > 0)
			{
				close((*pl)->pipefd[i][0]);
				close((*pl)->pipefd[i][1]);
			}
			return (0);
		}
		i++;
	}
	pipe_link(*pl);
	return (1);
}

void	pipe_link(t_pipeline *pl)
{
	int	i;

	i = 0;
	while (i < pl->cmd_counts)
	{
		if (pl->cmds[i]->in_fd == -1 && i > 0)
			pl->cmds[i]->in_fd = pl->pipefd[i - 1][0];
		if (pl->cmds[i]->out_fd == -1 && i < pl->cmd_counts - 1)
			pl->cmds[i]->out_fd = pl->pipefd[i][1];
		i++;
	}
}
