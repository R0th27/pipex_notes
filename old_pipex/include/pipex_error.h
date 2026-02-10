/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:53:54 by htoe              #+#    #+#             */
/*   Updated: 2026/02/08 07:51:02 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_ERROR_H
# define PIPEX_ERROR_H

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef enum e_error
{
	ERR_OK,
	ERR_USAGE,
	ERR_PIPE,
	ERR_FORK,
	ERR_MALLOC,
	ERR_DUP,
	ERR_INFILE,
	ERR_OUTFILE,
	ERR_CMD_NOT_FOUND,
	ERR_CMD_NO_EXEC,
	ERR_CMD_IS_DIR,
	ERR_EXEC
}	t_error;

int		error_return(t_error err, const char *target);
int		shell_error_code_from_errno(int err);

#endif