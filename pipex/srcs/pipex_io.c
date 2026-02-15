/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 01:09:33 by htoe              #+#    #+#             */
/*   Updated: 2026/02/15 01:35:52 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	setup_input_fd(t_input_type type, const char *arg)
{
	int	pfd[2];

	if (type == INPUT_FILE)
		return (open_file_rdonly(arg));
	if (pipe(pfd) == -1)
		return (-1);
	if (!heredoc_read(pfd[1], arg))
		return (close(pfd[0]), close(pfd[1]), -1);
	return (close(pfd[1]), pfd[0]);
}

int	setup_output_fd(t_input_type type, const char *arg)
{
	if (type == INPUT_HEREDOC)
		return (open_file_append(arg));
	return (open_file_trunc(arg));
}

int	open_file_rdonly(const char *path)
{
	return (open(path, O_RDONLY));
}

int	open_file_append(const char *path)
{
	return (open(path, O_CREAT | O_WRONLY | O_APPEND, 0644));
}

int	open_file_trunc(const char *path)
{
	return (open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644));
}
