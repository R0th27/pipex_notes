/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 08:30:07 by htoe              #+#    #+#             */
/*   Updated: 2026/01/14 10:08:45 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dsize)
{
	size_t	dlen;

	dlen = ft_strlen(dest);
	if (dlen >= dsize)
		return (dsize + ft_strlen(src));
	return (dlen + ft_strlcpy(dest + dlen, src, dsize - dlen));
}
