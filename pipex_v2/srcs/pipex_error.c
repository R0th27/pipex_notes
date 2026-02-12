/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 00:31:06 by htoe              #+#    #+#             */
/*   Updated: 2026/02/10 10:35:05 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_error.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "libft.h"

void	error_usage(void)
{
	error_print("Usage", "./pipex file1 cmd1 cmd2 file2\n");
	error_print("Usage", "./pipex file1 cmd1 cmd2 ... cmdx file2\n");
	error_print("Usage", "./pipex here_doc LIMITER cmd1 ... cmd2 file2\n");
}

void	error_command_not_found(const char *cmd)
{
	error_print(cmd, ": command not found\n");
}

void	error_print(const char *target, const char *message)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	if (target)
	{
		ft_putstr_fd((char *)target, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd((char *)message, STDERR_FILENO);
}

void	error_perror(const char *target)
{
	if (target)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		perror(target);
	}
	else
		perror("pipex");
}

int	error_code_from_errno(int err)
{
	if (err == ENOENT)
		return (127);
	else if (err == EACCES || err == EISDIR || err == ENOEXEC)
		return (126);
	return (1);
}
