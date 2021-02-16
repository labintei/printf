/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:44:03 by labintei          #+#    #+#             */
/*   Updated: 2021/02/16 12:07:09 by labintei         ###   ########.fr       */
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
	/*
	if(t == -2)
		return(0);
	if(t == 'c')
		return(ft_putchar(t));
	if(t == 's')
		return(ft_putstr())
	if(t == 'p')
		return(ft_print_p(va_arg()))
	if(t == 'd' || t == 'i')
		return(ft_print_int(va_arg(),1)
	if(t == 'u')
		return(ft_print_unsigned(va_arg(), 1)
	if(t == 'x' || t == 'X')
		return()
	if(t == '%')
		return(ft_putchar(t));
	*/
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
			i = ft_taille_flags(s);
			ret += print_flags(s + n, ap);
			n += i;
		}
	}
	va_end(ap);
	printf("\n%d",ret);
	return(ret);
}
