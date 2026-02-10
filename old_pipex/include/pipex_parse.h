/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 10:00:19 by htoe              #+#    #+#             */
/*   Updated: 2026/02/08 10:18:59 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PARSE_H
# define PIPEX_PARSE_H

# include <stdlib.h>
# include "pipex_cmd.h"
# include "pipex_error.h"
# include "pipex_io.h"
# include "pipex_pipeline.h"

t_input_type	detect_input_type(const char *arg);
t_pipeline		*parse_pipeline(int argc, char **argv, char **envp);

#endif
