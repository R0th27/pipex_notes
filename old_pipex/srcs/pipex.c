/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:47:05 by htoe              #+#    #+#             */
/*   Updated: 2026/02/09 19:08:23 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	pipex(int argc, char **argv, char **envp)
{
	t_pipeline	*pl;

	if (argc < 5)
		return (error_return(ERR_USAGE, NULL));
	pl = parse_pipeline(argc, argv, envp);
	pipeline_print(pl);
	pipeline_destroy(pl);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	status;

	status = pipex(argc, argv, envp);
	return (status);
}
