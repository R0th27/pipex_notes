/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 02:13:21 by htoe              #+#    #+#             */
/*   Updated: 2026/01/16 02:27:59 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		index;
	char	arr[10];

	num = n;
	if (num == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	index = 0;
	while (num > 0)
	{
		arr[index++] = (num % 10) + '0';
		num /= 10;
	}
	while (--index >= 0)
		write(fd, &arr[index], 1);
}
