/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:24:53 by labintei          #+#    #+#             */
/*   Updated: 2021/03/02 15:35:59 by labintei         ###   ########.fr       */
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

int		ft_print_type_c(struct f_flags *f, va_list ap, ...)
{
	int		d;
	int		i;

	d = 0;
	i = 0;
	i = (va_arg(ap, int));
	if((!(ft_find('-',f->indicateur))))
		d += ft_print_largeur(f,1);
	d += ft_putchar(i, 1);
	if(ft_find('-',f->indicateur))
		d += ft_print_largeur(f,1);
	return(d);
}

int		ft_print_type_s(struct f_flags *f, va_list ap, ...)
{
	char	*s;
	int		size;
	int		a;
	int		d;

	ft_init_int(&size,&a,&d);
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
	return(a + d);
}

int		ft_print_type_p(struct f_flags *f, va_list ap, ...)
{
	void	*v;
	int		size;
	int		z;
	int		d;
	int		g;
	int		a;

	ft_init_int(&d, &g, &z);
	a  = 0;
	v = va_arg(ap, void*);
	size = print_p(v, 0);
	if((v == NULL && f->intprecision == 0 && f->intprecision == '2'))
		return(a += ft_putstr("0x", 1, 0));
	if(f->intprecision == -2)
	{
		f->intprecision = 0;
		f->precision = 0;
	}
	if((f->precision == '2') && (v == 0))
	{
		if(f->largeur > 2)
			d += print_jusqua(' ',f->largeur, 2);
		d += ft_putstr("0x",1,0);
		if(f->intprecision > 2)
			d += print_jusqua('0',f->intprecision, 0);
		return(d);
	}
	if(ft_find('-',f->indicateur))
	{
		g += ft_putstr("0x", 1, 0);
		if(f->intprecision > 2)
			g += print_jusqua('0', f->intprecision, 0);
		g += print_p(v, 1);
	}
	if((f->intprecision > f->largeur) && (f->intprecision > size + 2))
	{
		d += ft_putstr("0x", 1, 0);
		d += print_jusqua('0', f->intprecision, size + 2);
		z = 1;
	}
	d += print_jusqua(' ',f->largeur, size + 2);
	if(g == 0)
	{
		if(z == 0)
			g += ft_putstr("0x", 1, 0);
		else
			g += ft_putstr("00", 1, 0);
		g += print_p(v, 1);
	}
	d += g;
	return(d);
}

int		ft_print_type_di(struct f_flags *f, va_list ap, ...)
{
	long int	l;
	int			d;
	int			neg;
	int			a;
	int			size;
	int			largeur;
	int			prec;

	ft_init_int(&largeur,&a,&d);
	l = va_arg(ap, int);
	(l < 0) ? (neg = 1) : (neg = 0);
	size = size_int(l, 10);
	if((f->precision == '2' && ((f->intprecision == -1) || ((f->intprecision == 0) && (l == 0)))))
		return((d += ft_print_largeur(f, 0)));
	if(f->intprecision == -2)
	{
		f->intprecision = 0;
		f->precision = 0;
	}
	if(f->intprecision == 0 && f->precision == '2')
		f->precision = 0;
	(f->intprecision > 0)? (prec = 1) : (prec = 0);
	(f->intprecision + neg > size) ? (largeur = f->intprecision + neg) : (largeur = size);
	if((!(ft_find('-',f->indicateur))) && ((((f->largeur > f->intprecision + neg) && (f->precision == '2') && (prec = 1))) || ((!(ft_find('0',f->indicateur))) && (prec == 0))))
		d += print_jusqua(' ', f->largeur, largeur);
	if(l < 0)
	{
		d += ft_putchar('-', 1);
		l *= -1;
	}
	if(((ft_find('0',f->indicateur) && ((f->precision != '2')) && (!(ft_find('-',f->indicateur))))))
		d += print_jusqua('0', f->largeur, size);
	if(prec == 1 && (f->intprecision + neg > size))
		a += print_jusqua('0', f->intprecision + neg , size);
	a += print_int(l, 1);
	if(ft_find('-',f->indicateur))
		d += print_jusqua(' ', f->largeur, largeur);
	return(a + d);
}

int		ft_print_type_u(struct f_flags *f, va_list ap, ...)
{
	unsigned int	u;
	int				size;
	int				a;
	int				d;
	int				g;
	int				n;

	ft_init_int(&a,&d,&g);
	n = 0;
	u = va_arg(ap, unsigned int);
	size = ft_unsigned(u, 0);
	if((f->precision == '2' && ((f->intprecision == -1) || ((f->intprecision == 0) && (u == 0)))))
		return(d += print_jusqua(' ',f->largeur, 0));
	if(f->intprecision == -2)
	{
		f->intprecision = 0;
		f->precision = 0;
	}
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
	return(a + d);
}

int		ft_print_type_xX(struct f_flags *f,va_list ap, ...)
{
	unsigned int	l;
	int			size;
	int			n;
	int			largeur;
	int			a;
	int			d;

	ft_init_int(&n,&a,&d);
	l = va_arg(ap, unsigned int);
	if(f->type == 'X')
		n = 1;
	size = basehexa(l, n, 0);
	if(l == 0 && (f->precision == '2') && (f->intprecision == 0) && (l == 0))
		return((d += print_jusqua(' ', f->largeur, 0)));
	if(f->intprecision == -2)
	{
		f->intprecision = 0;
		f->precision = 0;
	}
	(f->intprecision > size) ? (largeur = f->intprecision) : (largeur = size);
	if(((!(ft_find('-',f->indicateur))) && (!(ft_find('0',f->indicateur)))) || ((!(ft_find('-',f->indicateur))) && (ft_find('0',f->indicateur)) && (f->intprecision > 0) && (f->precision == '2')))
		d += print_jusqua(' ',f->largeur, largeur);
	if(f->precision == '2' && f->intprecision >= 0)
		d += print_jusqua('0',f->intprecision, size);
	if(ft_find('0',f->indicateur) && (f->precision != '2') && (f->intprecision <= 0))
		d += print_jusqua('0',f->largeur, largeur);
	a += basehexa(l, n, 1);
	if((ft_find('-',f->indicateur)))
		d += print_jusqua(' ',f->largeur,largeur);
	return(a + d);
}

int		ft_print_type_modulo(struct f_flags *f)
{
	int		a;
	int		d;

	a = 0;
	d = 0;
	/*if((!ft_find('P',f->indicateur)))
		d = ft_precision_diuxX(f, 1);*/
	if(ft_find('-',f->indicateur))
		a = ft_putchar('%', 1);
	d += ft_print_largeur(f, 1);
	if(a == 0)
		a += ft_putchar('%', 1);
	return(a + d);
}
