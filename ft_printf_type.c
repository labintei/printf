/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:24:53 by labintei          #+#    #+#             */
/*   Updated: 2021/02/17 14:42:11 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int		ft_print_type(char c, char y, va_list ap, ...)
{
	char	n;

	n = 0;
	if(c == 'c')
		return(ft_putchar(va_arg(ap, int), y));
	if(c == 's')
		return(ft_putstr(va_arg(ap, char*), y, 0));
	//REGARDER POUR LE 0
	if(c == 'p')
		return(print_p(va_arg(ap, int)));
	if(c == 'd' || c == 'i')
		return(print_int(va_arg(ap, int), y));
	if(c == 'u')
		return(ft_unsigned(va_arg(ap, unsigned int), y));
	if(c == 'x' || c == 'X')
	{
		if(c == 'X')
			n = 1;
		return(basehexa(va_arg(ap, long int), n, y));
	}
	if(c == '%')
		return(ft_putchar('%', y));
	return(-1);
}
