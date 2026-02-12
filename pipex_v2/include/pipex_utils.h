/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 03:51:14 by htoe              #+#    #+#             */
/*   Updated: 2026/02/10 09:25:06 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_UTILS_H
# define PIPEX_UTILS_H

# include "pipex_io.h"

t_input_type	detect_input_type(const char *arg);
int				heredoc_read(int fd, const char *limiter);
char			**extract_path_dirs(char **envp);
void			free_split(char **arr);

#endif