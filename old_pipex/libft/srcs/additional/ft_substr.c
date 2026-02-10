/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 00:54:38 by htoe              #+#    #+#             */
/*   Updated: 2026/01/15 12:53:01 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	clen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		clen = 0;
	else if (slen - start > len)
		clen = len;
	else
		clen = slen - start;
	sub = (char *)malloc(sizeof(char) * (clen + 1));
	if (!sub)
		return (NULL);
	if (clen)
		sub = ft_memcpy(sub, s + start, clen);
	sub[clen] = '\0';
	return (sub);
}
