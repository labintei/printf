/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:24:53 by labintei          #+#    #+#             */
/*   Updated: 2021/02/22 09:23:05 by labintei         ###   ########.fr       */
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
	return(j);
}

int		ft_print_largeur(struct f_flags *f, int size)
{
	int		a;
	int		n;

	a = 0;
	if(ft_find('0', f->indicateur) && ((f->largeur > f->intprecision) && (f->largeur > size) && f->precision == '2'))
	{
		n = size;
		if(f->intprecision > size)
			n = f->intprecision;
		return((a += print_jusqua(' ', f->largeur, n)));
	}
	if(ft_find('-', f->indicateur))
		return(a += print_jusqua(' ', f->largeur, size));
	if(ft_find('0', f->indicateur) && (!(ft_find('-', f->indicateur))))
		return(a += print_jusqua('0', f->largeur, size));
	if((!(ft_find('-',f->indicateur))) && (!(ft_find('0',f->indicateur))))
		return(a += print_jusqua(' ', f->largeur, size));
	return(a);
}

int		ft_print_largeur_c(struct f_flags *f, int size)
{
	int		i;

	i = 0;
	size = 1;
	if(f->largeur > 1)
	{
		while(i < f->largeur -1)
			i += ft_putchar(' ', 1);
	}
	return(i);
}

int		ft_print_largeur_bis(struct f_flags *f, int size)
{
	int		a;
	int		n;

	a = 0;
	n = 0;
	if((ft_find('0', f->indicateur) && (f->largeur > f->intprecision) && (f->largeur) > size))
	{
		n = size;
		if(size < f->intprecision)
			n = f->intprecision;
		return(a += print_jusqua(' ',f->largeur,  n + 1));
	}
	if((ft_find('-', f->indicateur)))
		return(a += print_jusqua(' ',f->largeur, size));
	if((ft_find('0', f->indicateur)) && (f->intprecision <= 0))
		return(a += print_jusqua('0', f->largeur, size));
	if((ft_find('0', f->indicateur)) && (f->intprecision > size))
		return(a += print_jusqua(' ', f->largeur, size));
	return(a += print_jusqua(' ',f->largeur, size));

}

int		ft_print_type(struct f_flags *f, va_list ap, ...)
{
	int		d;
	int		a;
	char	n;
	int		z;
	int		g;
	void	*v;
	char	*s;
	int		largeur;
	int		i;
	int				size;
	unsigned int	u;
	long int		l;

	n = 0;
	a = 0;
	d = 0;
	z = 0;
	g = 0;
	largeur = 0;
	if(f->type == 'c')
	{
		size = 1;
		i = (va_arg(ap, int));
		if((!(ft_find('-',f->indicateur))))
			d += ft_print_largeur(f,1);
		d += ft_putchar(i, 1);
		if(ft_find('-',f->indicateur))
			d += ft_print_largeur(f,1);
		return(d);
	}
	if(f->type == 's')
	{
		s = va_arg(ap, char*);
		if(s == NULL)
			s = "(null)";
		if((f->intprecision == 0) && (f->precision == '2') && (f->largeur == 0))
			return(0);
		if((f->intprecision == 0) && (f->precision == '2') && (f->largeur != 0))
			return(ft_print_largeur(f, 0));
		if(s)
			size = ft_putstr(s, 0, f->intprecision);
		else
			size = 0;
		if(ft_find('-', f->indicateur) && s)
			a += ft_putstr(s ,1, f->intprecision);
		d += ft_print_largeur(f, size);
		if(a == 0 && s)
			a += ft_putstr(s, 1, f->intprecision);
	}
	if(f->type == 'p')
	{
		v = va_arg(ap, void*);
		size = print_p((int)v, 0);
		if(f->intprecision == 0 && f->precision == '2')
			return(ft_putstr("0x", 1, 0));
		d += ft_precision_diuxX(f,size);
		if(ft_find('-', f->indicateur))
			a += print_p((int)v, 1);
		d += ft_print_largeur(f, size);
		if(a == 0)
			a += print_p((int)v, 1);
	}
	if(f->type == 'd' || f->type == 'i')
	{
		i = va_arg(ap, int);
		size = size_int((long)i, 10);
		if(f->precision == '2' && f->intprecision == 0)
			return((d += ft_print_largeur(f, 0)));
		if(((ft_find('0', f->indicateur)) && ((f->largeur < size) && (f->largeur < f->intprecision) && (f->intprecision != '2')) && (f->intprecision > size))
				|| (ft_find('0', f->indicateur) && (f->largeur > size) && (f->largeur > f->intprecision) && (f->intprecision <= 0)))
		{
			if(i < 0)
			{
				d += ft_putchar('-',1);
				size--;
				i *= -1;
			}
		}
		if(!(ft_find('-',f->indicateur)))
		{
			if(f->intprecision > size + d)
				d += ft_print_largeur(f, (f->intprecision));
			else
				d += ft_print_largeur(f,(size + d));
		}
		if(i < 0)
		{
			d += ft_putchar('-', 1);
			i *= -1;
			size--;
			n = 1;
		}
		d += ft_precision_diuxX(f, size);
		a += print_int(i,1);
		if(ft_find('-',f->indicateur))
			d += ft_print_largeur(f, size + d);
	}
	if(f->type == 'u')
	{
		u = va_arg(ap, unsigned int);
		size = ft_unsigned(u, 0);
		if((f->intprecision == 0) && (f->precision == '2'))
			return(d += ft_print_largeur(f, 0));
		if(ft_find('-', f->indicateur) && (f->precision != '2'))
			a = ft_unsigned(u, 1);
		if((f->precision != '2') || (((f->largeur > size) && (f->largeur > f->intprecision) && (f->precision == '2') && (!(ft_find('-', f->indicateur))))))
		{
			if(f->intprecision > size)
				d += ft_print_largeur(f, f->intprecision);
			else
				d += ft_print_largeur(f, size);
		}
		n += ft_precision_diuxX(f, size);
		if(a == 0)
			a += ft_unsigned(u, 1);
		if(d == 0)
		{
			g = size;
			if(f->intprecision > g)
				g = f->intprecision;
			d += ft_print_largeur(f, g);
		}
		d += n;
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
