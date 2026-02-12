/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:22:54 by htoe              #+#    #+#             */
/*   Updated: 2026/02/10 10:44:06 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_parse.h"
#include "pipex_io.h"
#include "pipex_utils.h"
#include <fcntl.h>
#include <unistd.h>

static t_error	init_fds(int argc, char **argv, int *in_fd, int *out_fd)
{
	t_input_type	type;
	int				start;

	type = detect_input_type(argv[1]);
	start = 1 + (type == INPUT_HEREDOC);
	*in_fd = setup_input_fd(type, argv[start]);
	if (*in_fd < 0)
	{
		if (type == INPUT_HEREDOC)
			return (error_perror("heredoc"), ERR_HEREDOC);
		return (error_perror(argv[1]), ERR_INFILE);
	}
	*out_fd = setup_output_fd(type, argv[argc - 1]);
	if (*out_fd < 0)
	{
		close(*in_fd);
		return (error_perror(argv[argc - 1]), ERR_OUTFILE);
	}
	return (ERR_OK);
}

t_error	parse_pipeline(int argc, char **argv, char **envp, t_pipeline **pl)
{
	int				in_fd;
	int				out_fd;
	int				start;
	t_input_type	type;
	t_error			err;

	type = detect_input_type(argv[1]);
	start = 2 + (type == INPUT_HEREDOC);
	err = init_fds(argc, argv, &in_fd, &out_fd);
	if (err != ERR_OK)
		return (err);
	*pl = pipeline_create(argc - start - 1);
	if (!*pl || !pipeline_fill_cmds(*pl, argv + start, envp))
	{
		close(in_fd);
		close(out_fd);
		pipeline_destroy(pl);
		return (error_perror("pipeline"), ERR_MALLOC);
	}
	pipeline_assign_endpoints(*pl, in_fd, out_fd);
	return (ERR_OK);
}
