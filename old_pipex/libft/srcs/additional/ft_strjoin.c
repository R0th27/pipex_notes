/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:57:18 by htoe              #+#    #+#             */
/*   Updated: 2026/01/15 13:06:55 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s2len = ft_strlen(s2);
	s1len = ft_strlen(s1);
	nstr = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!nstr)
		return (NULL);
	ft_memcpy(nstr, s1, s1len);
	ft_memcpy(nstr + s1len, s2, s2len);
	nstr[s1len + s2len] = '\0';
	return (nstr);
}
