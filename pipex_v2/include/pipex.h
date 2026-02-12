/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 00:09:02 by htoe              #+#    #+#             */
/*   Updated: 2026/02/10 07:12:20 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

int		pipex(int argc, char **argv, char **envp);

//test
void	error_print(const char *target, const char *message);
void	error_command_not_found(const char *cmd);
void	error_perror(const char *target);
int		error_code_from_errno(int err);

#endif
