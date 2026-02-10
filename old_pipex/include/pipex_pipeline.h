/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipeline.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 10:03:18 by htoe              #+#    #+#             */
/*   Updated: 2026/02/09 18:44:58 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PIPELINE_H
# define PIPEX_PIPELINE_H

# include <sys/types.h>
# include "pipex_cmd.h"

typedef struct s_pipeline
{
	t_cmd	**cmds;
	int		cmd_counts;
	pid_t	*pids;
}	t_pipeline;

t_pipeline	*pipeline_create(int cmd_count);
int			pipeline_fill_cmds(t_pipeline *pl, char **argv, char **envp);
void		pipeline_assign_fds(t_pipeline *pl, int in_fd, int out_fd);
void		pipeline_destroy(t_pipeline *pl);
int			pipeline_execute(t_pipeline *pl, char **envp);

#endif
