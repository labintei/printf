/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:44:03 by labintei          #+#    #+#             */
/*   Updated: 2021/02/17 15:42:04 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<stdio.h>

int		print_flags(const char *s, va_list ap, ...)
{
	struct f_flags	l;
	int				n;

	n = 0;
	ft_init_flags(&l);
	ft_define_flags(++s, &l);
	n = ft_print_flags(&l , ap);
	n += ft_printf_type(l.type, ap);
	return(n);
}

int		ft_print_flags(struct f_flags *f, va_list ap)
{
	return(1);
}

int		ft_printf_type(char t, va_list ap)
{
	if(t == 'c')
		return(ft_putchar(va_arg(ap, int), 1));
	if(t == 's')
		return(ft_putstr(va_arg(ap, char*), 1, 0));
	return(-1);
}

int		ft_printf(const char *s,...)
{
	int		n;
	int		i;
	int		ret;
	va_list	ap;


	ft_init_int(&n, &i, &ret);
	va_start(ap, s);
	while(s[n])
	{
		while(s[n] && s[n]!='%')
		{
			n += write(1, &s[n], 1);
			ret++;
		}
		if(s[n] == '%')
		{
			ret +=ft_print_type('u', 1, ap);
			n += 2;
		}
	}
	va_end(ap);
	printf("\n%d",ret);
	return(ret);
}
