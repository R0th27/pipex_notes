/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_io.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 03:19:50 by htoe              #+#    #+#             */
/*   Updated: 2026/02/10 03:51:53 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_IO_H
# define PIPEX_IO_H

# define HEREDOC_TMP ".heredoc_tmp"

typedef enum e_input_type
{
	INPUT_FILE,
	INPUT_HEREDOC
}	t_input_type;

int	open_file_rdonly(const char *path);
int	open_file_append(const char *path);
int	open_file_trunc(const char *path);
int	setup_input_fd(t_input_type type, const char *arg);
int	setup_output_fd(t_input_type type, const char *arg);

#endif