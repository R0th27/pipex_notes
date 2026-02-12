/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 07:44:24 by htoe              #+#    #+#             */
/*   Updated: 2026/02/10 08:33:49 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_paths.h"
#include "pipex_utils.h"
#include "libft.h"
#include <unistd.h>
#include <stddef.h>

static char	*join_path_cmd(const char *path, const char *cmd)
{
	char	*path_slash;
	char	*path_full;

	path_slash = ft_strjoin(path, "/");
	if (!path_slash)
		return (NULL);
	path_full = ft_strjoin(path_slash, cmd);
	free(path_slash);
	return (path_full);
}

static char	**build_candidates(char **dirs, const char *cmd)
{
	char	**candidates;
	int		i;

	i = 0;
	while (dirs[i])
		i++;
	candidates = (char **)malloc(sizeof(char *) * (i + 1));
	if (!candidates)
		return (NULL);
	i = -1;
	while (dirs[++i])
		candidates[i] = join_path_cmd(dirs[i], cmd);
	candidates[i] = NULL;
	return (candidates);
}

static int	check_candidates(char **candidates)
{
	int	i;

	i = -1;
	while (candidates[++i])
	{
		if (!access(candidates[i], F_OK))
			return (1);
	}
	return (0);
}

char	**paths_builder(char *cmd_str, char **dirs)
{
	char	**paths;

	if (ft_strchr(cmd_str, '/'))
		return (ft_split(cmd_str, ' '));
	paths = build_candidates(dirs, cmd_str);
	if (!check_candidates(paths))
		return (free_split(paths), NULL);
	return (paths);
}
