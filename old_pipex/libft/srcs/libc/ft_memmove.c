/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 07:20:43 by htoe              #+#    #+#             */
/*   Updated: 2026/01/14 08:12:34 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*str;

	if (dest == src || !n)
		return (dest);
	dst = (unsigned char *)dest;
	str = (const unsigned char *)src;
	if (dst < str)
	{
		while (n--)
			*dst++ = *str++;
	}
	else
	{
		while (n--)
			*(dst + n) = *(str + n);
	}
	return (dest);
}
