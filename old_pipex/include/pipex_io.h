/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_io.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 06:05:11 by htoe              #+#    #+#             */
/*   Updated: 2026/02/10 03:22:16 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_IO_H
# define PIPEX_IO_H

# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include "libft.h"
# include "pipex_error.h"

typedef enum e_input_type
{
	INPUT_FILE,
	INPUT_HEREDOC
}	t_input_type;

int	open_infile(const char *path);
int	open_outfile(const char *path, int append);
int	setup_input_fd(t_input_type type, const char *arg);
int	setup_output_fd(t_input_type type, const char *arg);
int	heredoc_read(const char *limiter);

#endif
