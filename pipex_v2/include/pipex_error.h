/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 00:31:02 by htoe              #+#    #+#             */
/*   Updated: 2026/02/10 10:31:00 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_ERROR_H
# define PIPEX_ERROR_H

typedef enum e_error
{
	ERR_OK,
	ERR_USAGE,
	ERR_INFILE,
	ERR_HEREDOC,
	ERR_OUTFILE,
	ERR_MALLOC,
	ERR_CMD_NOT_FOUND,
	ERR_EXEC,
	ERR_PIPE,
	ERR_FORK,
	ERR_DUP2
}	t_error;

void	error_usage(void);
void	error_command_not_found(const char *cmd);
void	error_print(const char *target, const char *message);
void	error_perror(const char *target);
int		error_code_from_errno(int err);

#endif