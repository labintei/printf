/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:44:03 by labintei          #+#    #+#             */
/*   Updated: 2021/02/24 10:29:35 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int		print_flags(const char *s, va_list ap, ...)
{
	struct f_flags	l;
	int				n;
	char			c;

	c = 1;
	n = 0;
	ft_init_flags(&l);
	ft_define_flags(++s, &l, ap);
	if(l.type=='c')
		return(ft_print_type_c(&l, ap));
	if(l.type=='s')
		return(ft_print_type_s(&l, ap));
	if(l.type=='p')
		return(ft_print_type_p(&l, ap));
	if(l.type=='d' || l.type == 'i')
		return(ft_print_type_di(&l, ap));
	if(l.type=='u')
		return(ft_print_type_u(&l, ap));
	if(l.type=='x' || l.type == 'X')
		return(ft_print_type_xX(&l, ap));
	if(l.type=='%')
		return(ft_print_type_modulo(&l));
	return(0);
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
			
			i = ft_taille_flags(s + n);
			ret += print_flags(s + n, ap);
			n += i;
		}
	}
	va_end(ap);
	return(ret);
}
