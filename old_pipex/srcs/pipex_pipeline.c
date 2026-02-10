/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:55:40 by htoe              #+#    #+#             */
/*   Updated: 2026/02/09 18:59:22 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_pipeline.h"

t_pipeline	*pipeline_create(int cmd_count)
{
	t_pipeline	*pl;

	pl = (t_pipeline *)malloc(sizeof(t_pipeline));
	if (!pl)
		return (NULL);
	pl -> cmd_counts = cmd_count;
	pl -> cmds = ft_calloc(cmd_count, sizeof(t_cmd *));
	if (!pl -> cmds)
		return (free(pl), NULL);
	pl -> pids = (pid_t *)malloc(sizeof(pid_t) * cmd_count);
	if (!pl -> pids)
		return (free(pl -> cmds), free(pl), NULL);
	return (pl);
}

int	pipeline_fill_cmds(t_pipeline *pl, char **argv, char **envp)
{
	int	i;

	i = -1;
	while (++i < pl -> cmd_counts)
	{
		pl -> cmds[i] = cmd_create(argv[i], envp);
		if (!pl -> cmds[i])
		{
			while (i > 0)
				cmd_destroy(pl -> cmds[--i]);
			return (0);
		}
	}
	return (1);
}

void	pipeline_assign_fds(t_pipeline *pl, int in_fd, int out_fd)
{
	pl -> cmds[0]-> in_fd = in_fd;
	pl -> cmds[(pl -> cmd_counts) - 1]-> out_fd = out_fd;
}

void	pipeline_destroy(t_pipeline *pl)
{
	int	i;

	if (!pl)
		return ;
	if (pl -> cmds)
	{
		i = -1;
		while (++i < pl -> cmd_counts)
		{
			if (pl -> cmds[i])
				cmd_destroy(pl -> cmds[i]);
		}
		free(pl -> cmds);
	}
	if (pl -> pids)
		free(pl -> pids);
	free(pl);
}
