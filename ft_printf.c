/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:44:03 by labintei          #+#    #+#             */
/*   Updated: 2021/02/18 14:39:41 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<stdio.h>

int		print_flags(const char *s, va_list ap, ...)
{
	struct f_flags	l;
	int				n;
	char			c;

	c = 1;
	n = 0;
	ft_init_flags(&l);
	ft_define_flags(++s, &l);
	ft_precision_f(&l, ap);
	//n = ft_print_flags(&l , ap);()()
	printf("\nTYPE CHECK %c", l.type);
	printf("\n");
	n += ft_print_type((l.type), c, ap);
	return(n);
}

int		ft_print_flags(struct f_flags *f, va_list ap)
{

	return(1);
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
			
			printf("TAILLE FLAGS i%d\ni",(i = ft_taille_flags(s + n)));
			ret += print_flags(s + n, ap);
			n += i;
		}
	}
	va_end(ap);
	return(ret);
}
