/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:47:08 by htoe              #+#    #+#             */
/*   Updated: 2026/01/21 02:16:38 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	pf_putchar(char c);
void	pf_putstr(char *str);
void	pf_putpointer(void *ptr);
void	pf_putnbr(long long num);
void	pf_puthex(unsigned int num, int flag);

#endif