/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 00:55:35 by htoe              #+#    #+#             */
/*   Updated: 2026/02/15 07:45:27 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_usage(void)
{
	error_print("Usage", "./pipex file1 cmd1 cmd2 file2\n");
	error_print("Usage", "./pipex file1 cmd1 cmd2 ... cmdx file2\n");
	error_print("Usage", "./pipex here_doc LIMITER cmd1 ... cmd2 file2\n");
}

void	error_cmd_not_found(const char *cmd)
{
	error_print(cmd, "command not found\n");
}

void	error_print(const char *target, const char *message)
{
	char	buffer[1024];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ("pipex: "[j])
		buffer[i++] = "pipex: "[j++];
	j = 0;
	while (target && target[j])
		buffer[i++] = target[j++];
	buffer[i++] = ':';
	buffer[i++] = ' ';
	j = 0;
	while (message[j])
		buffer[i++] = message[j++];
	write(STDERR_FILENO, buffer, i);
}

void	error_perror(const char *target)
{
	if (target)
		perror(target);
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
