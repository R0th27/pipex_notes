/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 03:20:17 by htoe              #+#    #+#             */
/*   Updated: 2026/02/09 18:33:41 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

char	*join_path(const char *path, const char *cmd)
{
	char	*path_slash;
	char	*full_path;

	path_slash = ft_strjoin((const char *)path, "/");
	full_path = ft_strjoin((const char *)path_slash, cmd);
	free(path_slash);
	return (full_path);
}

char	**path_list(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*resolve_path(const char *cmd, char **envp)
{
	char	**paths;
	char	*candidate;
	int		i;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	paths = path_list(envp);
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		candidate = join_path(paths[i], cmd);
		if (!access(candidate, X_OK))
			return (free_split(paths), candidate);
		free(candidate);
	}
	return (free_split(paths), NULL);
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
