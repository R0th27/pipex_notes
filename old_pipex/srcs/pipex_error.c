/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 00:02:03 by htoe              #+#    #+#             */
/*   Updated: 2026/02/09 18:58:33 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_error.h"

int	error_return(t_error err, const char *target)
{
	if (err == ERR_USAGE)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", STDERR_FILENO);
		return (1);
	}
	else if (err == ERR_MALLOC)
		errno = ENOMEM;
	if (target)
		perror(target);
	else
		perror("pipex");
	return (shell_error_code_from_errno(errno));
}

int	shell_error_code_from_errno(int err)
{
	if (err == ENOENT)
		return (127);
	else if (err == EACCES || err == EISDIR)
		return (126);
	return (1);
}
