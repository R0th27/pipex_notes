/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:40:59 by htoe              #+#    #+#             */
/*   Updated: 2026/02/15 03:31:18 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**extract_path_dirs(char **envp)
{
	int	i;

	if (!envp || !*envp)
		return (NULL);
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

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
	{
		candidates[i] = join_path_cmd(dirs[i], cmd);
		if (!candidates[i])
			return (free_split(candidates), NULL);
	}
	candidates[i] = NULL;
	return (candidates);
}

char	**paths_builder(char *cmd_str, char **dirs)
{
	char	**paths;

	if (ft_strchr(cmd_str, '/'))
		return (ft_split(cmd_str, ' '));
	if (!dirs || !*dirs)
		return (NULL);
	paths = build_candidates(dirs, cmd_str);
	return (paths);
}
