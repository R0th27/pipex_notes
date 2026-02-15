/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 01:03:20 by htoe              #+#    #+#             */
/*   Updated: 2026/02/15 08:55:54 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	usage_check(int argc, char **argv)
{
	if (argc < 5)
	{
		error_usage();
		exit(1);
	}
	else if (detect_input_type(argv[1]) == INPUT_HEREDOC && argc < 6)
	{
		error_usage();
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipeline	*pl;
	t_error		err;
	int			status;

	usage_check(argc, argv);
	err = parse_pipeline(argc, argv, envp, &pl);
	if (err == ERR_MALLOC)
		return (1);
	else if (err == ERR_PIPE)
		return (0);
	status = fork_pipeline(pl, envp);
	pipeline_destroy(&pl);
	while (wait(NULL) > 0)
		;
	return (status);
}
