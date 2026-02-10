/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 22:33:17 by htoe              #+#    #+#             */
/*   Updated: 2026/01/16 01:34:30 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fillnum(char *str, int *arr, int index, int neg_flag)
{
	int	i;

	i = 0;
	if (neg_flag)
		str[i++] = '-';
	while (index--)
		str[i++] = arr[index] + '0';
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	long	num;
	int		array[10];
	int		i;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	if (num < 0)
		num *= -1;
	i = 0;
	while (num > 0)
	{
		array[i++] = num % 10;
		num /= 10;
	}
	str = (char *)malloc(sizeof(char) * (i + (n < 0) + 1));
	if (!str)
		return (NULL);
	ft_fillnum(str, array, i, n < 0);
	return (str);
}
