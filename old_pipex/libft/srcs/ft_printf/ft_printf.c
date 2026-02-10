/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:57:27 by htoe              #+#    #+#             */
/*   Updated: 2026/01/19 03:42:31 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_count(int flag)
{
	static int	count = 0;

	count++;
	count *= flag;
	return (count);
}

void	pf_putchar(char c)
{
	write(1, &c, 1);
	pf_count(1);
}

void	pf_putstr(char *str)
{
	if (!str)
		return (pf_putstr("(null)"));
	while (*str)
		pf_putchar(*str++);
}

static void	pf_formatparser(va_list args, char c)
{
	if (c == '%')
		pf_putchar('%');
	else if (c == 'c')
		pf_putchar(va_arg(args, int));
	else if (c == 's')
		pf_putstr(va_arg(args, char *));
	else if (c == 'p')
		pf_putpointer(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		pf_putnbr(va_arg(args, int));
	else if (c == 'u')
		pf_putnbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		pf_puthex(va_arg(args, unsigned int), c == 'X');
}

int	ft_printf(const char *str, ...)
{
	int		byte;
	va_list	args;

	va_start(args, str);
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '%')
			pf_formatparser(args, *(++str));
		else
			pf_putchar(*str);
		if (*str)
			str++;
	}
	byte = pf_count(1) - 1;
	pf_count(0);
	va_end(args);
	return (byte);
}
