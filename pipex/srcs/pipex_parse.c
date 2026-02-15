/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 04:25:30 by htoe              #+#    #+#             */
/*   Updated: 2026/02/15 07:18:03 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_fds(int argc, char **argv, int start, t_files *files)
{
	t_input_type	type;

	type = detect_input_type(argv[1]);
	files->infile = setup_input_fd(type, argv[start]);
	if (files->infile < 0)
	{
		if (type == INPUT_HEREDOC)
			error_perror("heredoc");
		else
			error_perror(argv[1]);
	}
	files->outfile = setup_output_fd(type, argv[argc - 1]);
	if (files->outfile < 0)
		error_perror(argv[argc - 1]);
}

t_error	parse_pipeline(int argc, char **argv, char **envp, t_pipeline **pl)
{
	int				start;
	t_files			files;
	t_input_type	type;

	type = detect_input_type(argv[1]);
	start = 1 + (type == INPUT_HEREDOC);
	init_fds(argc, argv, start++, &files);
	*pl = pipeline_create(argc - start - 1);
	if (!*pl || !pipeline_fill_cmds(*pl, argv + start, envp))
	{
		close(files.infile);
		close(files.outfile);
		return (pipeline_destroy(pl), error_perror("pipeline"), ERR_MALLOC);
	}
	pipeline_assign_endpoints(*pl, files.infile, files.outfile);
	if (!pipe_construct(pl))
	{
		close(files.infile);
		close(files.outfile);
		return (pipeline_destroy(pl), error_perror("pipe"), ERR_PIPE);
	}
	return (ERR_OK);
}
