/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 03:52:13 by htoe              #+#    #+#             */
/*   Updated: 2026/02/10 09:25:13 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"
#include "pipex_io.h"
#include "libft.h"
#include <unistd.h>

t_input_type	detect_input_type(const char *arg)
{
	if (!ft_strncmp(arg, "here_doc", 9))
		return (INPUT_HEREDOC);
	return (INPUT_FILE);
}

int	heredoc_read(int fd, const char *limiter)
{
	char	*line;
	size_t	len;

	len = ft_strlen(limiter) + 1;
	line = get_next_line(STDIN_FILENO);
	while (line && ft_strncmp(line, limiter, len) != '\n')
	{
		if (write(fd, line, ft_strlen(line)) == -1)
			return (free(line), 0);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	return (1);
}

char	**extract_path_dirs(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
