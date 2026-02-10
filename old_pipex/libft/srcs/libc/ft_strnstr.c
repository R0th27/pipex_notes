/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:44:32 by htoe              #+#    #+#             */
/*   Updated: 2026/01/14 12:16:54 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!*little)
		return ((char *)big);
	while (*big && len)
	{
		i = 0;
		while ((len - i) && *(big + i) && *(little + i) == *(big + i))
		{
			i++;
			if (!*(little + i))
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}
