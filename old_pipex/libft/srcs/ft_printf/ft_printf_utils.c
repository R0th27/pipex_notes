/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 00:13:35 by htoe              #+#    #+#             */
/*   Updated: 2026/01/19 03:55:12 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_puthex(unsigned int num, int flag)
{
	int		i;
	int		arr[8];
	char	*l_hex;
	char	*c_hex;
	char	*hex;

	if (!num)
		return (pf_putchar('0'));
	l_hex = "0123456789abcdef";
	c_hex = "0123456789ABCDEF";
	hex = l_hex;
	if (flag)
		hex = c_hex;
	i = 0;
	while (num > 0)
	{
		arr[i++] = num % 16;
		num /= 16;
	}
	while (--i >= 0)
		pf_putchar(hex[arr[i]]);
}

void	pf_putnbr(long long num)
{
	int	i;
	int	arr[10];

	if (!num)
		return (pf_putchar('0'));
	if (num < 0)
	{
		pf_putchar('-');
		num *= -1;
	}
	i = 0;
	while (num > 0)
	{
		arr[i++] = num % 10;
		num /= 10;
	}
	while (--i >= 0)
		pf_putchar(arr[i] + '0');
}

void	pf_putpointer(void *ptr)
{
	unsigned long long	num;
	int					i;
	int					arr[16];
	char				*hex;

	if (!ptr)
		return (pf_putstr("(nil)"));
	pf_putstr("0x");
	num = (unsigned long long)ptr;
	i = 0;
	while (num > 0)
	{
		arr[i++] = num % 16;
		num /= 16;
	}
	hex = "0123456789abcdef";
	while (--i >= 0)
		pf_putchar(hex[arr[i]]);
}
