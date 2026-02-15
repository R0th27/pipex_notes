/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 23:11:40 by htoe              #+#    #+#             */
/*   Updated: 2026/02/15 04:28:20 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_TYPES_H
# define PIPEX_TYPES_H

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

typedef enum e_input_type
{
	INPUT_FILE,
	INPUT_HEREDOC
}	t_input_type;

typedef struct s_cmd
{
	char	**argv;
	char	**paths;
	int		in_fd;
	int		out_fd;
}	t_cmd;

typedef struct s_pipeline
{
	t_cmd	**cmds;
	int		cmd_counts;
	int		(*pipefd)[2];
}	t_pipeline;

typedef struct s_files
{
	int	infile;
	int	outfile;
}	t_files;

#endif
