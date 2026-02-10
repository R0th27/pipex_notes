/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:27:57 by htoe              #+#    #+#             */
/*   Updated: 2026/01/14 10:44:15 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*x;

	x = s;
	while (*x)
		x++;
	while (x >= s)
	{
		if (*x == (unsigned char)c)
			return ((char *)x);
		x--;
	}
	return (NULL);
}
