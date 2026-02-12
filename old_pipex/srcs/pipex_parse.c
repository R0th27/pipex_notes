/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 10:00:42 by htoe              #+#    #+#             */
/*   Updated: 2026/02/10 11:01:04 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_parse.h"

t_input_type	detect_input_type(const char *arg)
{
	if (!ft_strncmp(arg, "here_doc", 9))
		return (INPUT_HEREDOC);
	return (INPUT_FILE);
}

t_pipeline	*parse_pipeline(int argc, char **argv, char **envp)
{
	t_pipeline		*pl;
	int				in_fd;
	int				out_fd;
	t_input_type	type;
	int				start;

	type = detect_input_type(argv[1]);
	start = 1 + (type == INPUT_HEREDOC);
	in_fd = setup_input_fd(type, argv[start++]);
	out_fd = setup_output_fd(type, argv[argc - 1]);
	if (in_fd < 0 || out_fd < 0)
		return (NULL);
	pl = pipeline_create(argc - start - 1);
	if (!pl)
	{
		close(in_fd);
		close(out_fd);
		return (error_return(ERR_MALLOC, NULL), NULL);
	}
	if (!pipeline_fill_cmds(pl, argv + start, envp))
		return (pipeline_destroy(pl), close(in_fd), close(out_fd), NULL);
	pipeline_assign_fds(pl, in_fd, out_fd);
	return (pl);
}
