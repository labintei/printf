/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:24:53 by labintei          #+#    #+#             */
/*   Updated: 2021/03/05 10:28:12 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_type_p(struct s_flags *f, va_list ap, ...)
{
	void	*v;
	int		size;
	int		g;

	g = 0;
	v = va_arg(ap, void*);
	init(f, 0, 0, 0);
	size = print_p(f, v, 0);
	if ((!ft_find('-', f->i)) && (!ft_find('0', f->i)))
		g += print_j(' ', f->l, size);
	g += print_p(f, v, 1);
	if (ft_find('-', f->i))
		g += print_j(' ', f->l, size);
	return (g);
}

int		init(struct s_flags *f, int neg, int size, char y)
{
	int		largeur;
	int		prec;

	if (f->ip == -2 && (y == 1 || y == 0))
	{
		f->ip = 0;
		f->p = 0;
	}
	f->p = (f->ip == 0 && f->p == '2' && y == 1) ? 0 : f->p;
	if (y == 2)
	{
		prec = (f->ip > 0) ? 1 : 0;
		largeur = (f->ip + neg > size) ? f->ip + neg : size;
		if ((!(ft_find('-', f->i))) && ((((f->l > f->ip + neg) && (f->p == '2')\
		&& (prec = 1))) || ((!(ft_find('0', f->i))) && (prec == 0))))
			return (print_j(' ', f->l, largeur));
	}
	return (0);
}

int		ft_print_type_di(struct s_flags *f, va_list ap, ...)
{
	long int	l;
	int			neg;
	int			a;
	int			size;

	ft_init_int(&size, &a, &neg);
	l = va_arg(ap, int);
	neg = (l < 0) ? 1 : 0;
	size = size_int(l, 10);
	if ((f->p == '2' && ((f->ip == -1) || ((f->ip == 0) && (l == 0)))))
		return ((a += print_j(' ', f->l, 0)));
	init(f, 0, 0, 1);
	a += init(f, neg, size, 2);
	a += ft_di(&l);
	a += ft_di_bis(f, neg, size, 1);
	a += print_int(l, 1);
	a += ft_di_bis(f, neg, size, 2);
	return (a);
}

int		ft_print_type_u(struct s_flags *f, va_list ap, ...)
{
	unsigned int	u;
	int				size;
	int				a;
	int				largeur;

	ft_init_int(&size, &largeur, &a);
	u = va_arg(ap, unsigned int);
	size = ft_unsigned(u, 0);
	largeur = (f->ip > size) ? f->ip : size;
	if ((f->p == '2' && ((f->ip == -1) || ((f->ip == 0) && (u == 0)))))
		return (a += print_j(' ', f->l, 0));
	init(f, 0, 0, 1);
	if ((!ft_find('-', f->i) && (ft_find('0', f->i) && (f->p == '2') && \
		(f->ip > size))) || (!ft_find('0', f->i) && (!ft_find('-', f->i)))
			|| (((!ft_find('0', f->i) || f->p == '2') && !ft_find('-', f->i))))
		a += print_j(' ', f->l, largeur);
	if (f->p == '2' && f->ip > size)
		a += print_j('0', f->ip, size);
	if (a == 0 && (!ft_find('-', f->i)) && (ft_find('0', f->i)))
		a += print_j('0', f->l, size);
	a += ft_unsigned(u, 1);
	if (ft_find('-', f->i) && (f->p == '2' || f->ip < size))
		a += print_j(' ', f->l, largeur);
	return (a);
}

int		ft_print_type_x(struct s_flags *f, va_list ap, ...)
{
	unsigned int	l;
	int				size;
	int				n;
	int				largeur;
	int				a;

	ft_init_int(&n, &a, &largeur);
	l = va_arg(ap, unsigned int);
	n = (f->type == 'X') ? 1 : 0;
	size = basehexa(l, n, 0);
	if (l == 0 && (f->p == '2') && (f->ip == 0) && (l == 0))
		return ((a += print_j(' ', f->l, 0)));
	init(f, 0, 0, 1);
	largeur = (f->ip > size) ? f->ip : size;
	if ((!(ft_find('-', f->i)) && (!ft_find('0', f->i))) || \
		((!ft_find('-', f->i)) && (ft_find('0', f->i)) && (f->ip > 0) && \
		(f->p == '2')))
		a += print_j(' ', f->l, largeur);
	a += (f->p == '2' && f->ip >= 0) ? print_j('0', f->ip, size) : 0;
	if (ft_find('0', f->i) && (f->p != '2') && (f->ip <= 0))
		a += print_j('0', f->l, largeur);
	a += basehexa(l, n, 1);
	if ((ft_find('-', f->i)))
		a += print_j(' ', f->l, largeur);
	return (a);
}
