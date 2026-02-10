/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 08:02:48 by htoe              #+#    #+#             */
/*   Updated: 2026/01/14 08:26:50 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dsize)
{
	size_t	ssize;

	ssize = ft_strlen(src);
	if (!dsize)
		return (ssize);
	dsize--;
	while (dsize-- && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (ssize);
}
