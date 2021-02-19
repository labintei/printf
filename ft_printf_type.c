/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:24:53 by labintei          #+#    #+#             */
/*   Updated: 2021/02/19 15:03:53 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int		print_jusqua(char c, int i,int start)
{
	int		j;

	j = 0;
	if(start >= i)
		return(0);
	--start;
	while(++start < i)
	{
		j += ft_putchar((int)c , 1);
	}
	return(j);
}

int		ft_precision_diuxX(struct f_flags *f, int size)
{
	int		j;

	j = 0;
	if(f->intprecision > 0)
		j = print_jusqua('0', f->intprecision ,size);
	return(0);
}

int		ft_print_largeur(struct f_flags *f, int size)
{
	int		a;
	int		largeurstock;
	a = 0;
	if(ft_find('-', f->indicateur))
		a += print_jusqua(' ', f->largeur, size);
	if(ft_find('0', f->indicateur) && (!(ft_find('-', f->indicateur))))
		a += print_jusqua('0', f->largeur, size);
	if((!(ft_find('-',f->indicateur))) && (!(ft_find('0',f->indicateur))))
		a += print_jusqua(' ', f->largeur, size);
	return(a);
}


int		ft_print_type(struct f_flags *f, char y, va_list ap, ...)
{
	int		d;
	int		a;
	char	n;
	char	*s;
	int		i;
	int				size;
	unsigned int	u;
	long int		l;

	n = 0;
	a = 0;
	if(f->type == 'c')
		return(ft_putchar(va_arg(ap, int), y));
	if(f->type == 's')
	{
		s = va_arg(ap, char*);
		size = ft_putstr(s, 0, f->intprecision);
		if(ft_find('-', f->indicateur))
			a += ft_putstr(s ,1, f->intprecision);
		d += ft_print_largeur(f, size);
		if(a == 0)
			a += ft_putstr(s, 1, f->intprecision);
	}
	if(f->type == 'p')
	{
		i = va_arg(ap, int);
		size = print_p(i, 0);
		d += ft_precision_diuxX(f,size);
		if(ft_find('-', f->indicateur))
			a += print_p(i, 1);
		d += ft_print_largeur(f, size);
		if(a == 0)
			a += print_p(i, 1);
	}
	if(f->type == 'd' || f->type == 'i')
	{
		i = va_arg(ap, int);
		size = print_int(i, 0);
		d += ft_precision_diuxX(f, size);
		if(ft_find('-', f->indicateur))
			a = print_int(i, 1);
		d = ft_print_largeur(f, size);
		if(a == 0)
			a += print_int(i, 1);
	}
	if(f->type == 'u')
	{
		u = va_arg(ap, unsigned int);
		size = ft_unsigned(u, 0);
		d += ft_precision_diuxX(f,size);
		if(ft_find('-', f->indicateur))
			a = ft_unsigned(u, 1);
		d += ft_print_largeur(f, size);
		if(a == 0)
			a += ft_unsigned(u, 1);
	}
	if(f->type == 'x' || f->type == 'X')
	{
		l = va_arg(ap, long int);
		d += ft_precision_diuxX(f, size);
		if(f->type == 'X')
			n = 1;
		size = basehexa(l, n, 0);
		if(ft_find('-',f->indicateur))
			a = basehexa(l, n, 1);
		d += ft_print_largeur(f, size);
		if(a == 0)
			a += basehexa(l, n, 1);
	}
	if(f->type == '%')
	{
		d += ft_precision_diuxX(f, (size = 1));
		if(ft_find('-',f->indicateur))
			a = ft_putchar('%', 1);
		d += ft_print_largeur(f, size);
		if(a == 0)
			a += ft_putchar('%', 1);
	}
	return(a + d);
}
