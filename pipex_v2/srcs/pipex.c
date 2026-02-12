/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 00:09:00 by htoe              #+#    #+#             */
/*   Updated: 2026/02/10 10:46:43 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "pipex_error.h"
#include "pipex_io.h"
#include "pipex_cmd.h"
#include "pipex_utils.h"
#include "pipex_pipeline.h"
#include "pipex_parse.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void	print_pipeline(t_pipeline *pl);

int	pipex(int argc, char **argv, char **envp)
{
	t_error		err;
	t_pipeline	*pl;

	if (argc < 5)
		return (error_usage(), 1);
	err = parse_pipeline(argc, argv, envp, &pl);
	print_pipeline(pl);
	pipeline_destroy(&pl);
	if (err != ERR_OK)
		return (1);
	return (0);
}
