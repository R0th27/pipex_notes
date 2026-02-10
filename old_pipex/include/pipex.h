/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 01:10:06 by htoe              #+#    #+#             */
/*   Updated: 2026/02/09 19:10:50 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>

# include "libft.h"
# include "pipex_error.h"
# include "pipex_utils.h"
# include "pipex_cmd.h"
# include "pipex_io.h"
# include "pipex_pipeline.h"
# include "pipex_parse.h"

int	pipex(int argc, char **argv, char **envp);

//test
void	pipeline_print(t_pipeline *pl);

#endif
