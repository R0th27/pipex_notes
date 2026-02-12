/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:22:12 by htoe              #+#    #+#             */
/*   Updated: 2026/02/10 09:48:27 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PARSE_H
# define PIPEX_PARSE_H

# include "pipex_error.h"
# include "pipex_pipeline.h"

t_error	parse_pipeline(int argc, char **argv, char **envp, t_pipeline **pl);

#endif
