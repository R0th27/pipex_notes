/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 01:36:59 by htoe              #+#    #+#             */
/*   Updated: 2026/01/16 01:51:58 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*nstr;

	if (!s || !f)
		return (NULL);
	nstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!nstr)
		return (NULL);
	index = 0;
	while (s[index])
	{
		nstr[index] = f(index, s[index]);
		index++;
	}
	nstr[index] = '\0';
	return (nstr);
}
