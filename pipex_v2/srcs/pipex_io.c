/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 03:19:56 by htoe              #+#    #+#             */
/*   Updated: 2026/02/10 03:52:54 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_io.h"
#include "pipex_utils.h"
#include <fcntl.h>
#include <unistd.h>

int	setup_input_fd(t_input_type type, const char *arg)
{
	int	fd;

	if (type == INPUT_FILE)
		return (open_file_rdonly(arg));
	fd = open_file_trunc(HEREDOC_TMP);
	if (fd < 0)
		return (-1);
	if (!heredoc_read(fd, arg))
		return (close(fd), unlink(HEREDOC_TMP), -1);
	close(fd);
	fd = open_file_rdonly(HEREDOC_TMP);
	unlink(HEREDOC_TMP);
	return (fd);
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
