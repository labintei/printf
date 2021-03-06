/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_charstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:55:23 by labintei          #+#    #+#             */
/*   Updated: 2021/03/06 16:33:52 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_type_modulo(struct s_flags *f)
{
	int		a;

	a = 0;
	if ((f->p == '2') && (f->ip <= 0))
		f->p = 0;
	if ((!(ft_find('-', f->i))) && (!(ft_find('0', f->i))))
		a += print_j(' ', f->l, 1);
	if (ft_find('0', f->i) && (!(ft_find('-', f->i))))
		a += print_j('0', f->l, 1);
	a += ft_putchar('%', 1);
	if (ft_find('-', f->i))
		a += print_j(' ', f->l, 1);
	return (a);
}

int		ft_print_type_c(struct s_flags *f, va_list ap, ...)
{
	int		d;
	int		i;

	d = 0;
	i = (va_arg(ap, int));
	if ((!(ft_find('-', f->i))))
		d += print_j(' ', f->l, 1);
	d += ft_putchar(i, 1);
	if (ft_find('-', f->i))
		d += print_j(' ', f->l, 1);
	return (d);
}

int		ft_print_type_s(struct s_flags *f, va_list ap, ...)
{
	char	*s;
	int		size;
	int		a;
	int		d;

	ft_init_int(&size, &a, &d);
	s = va_arg(ap, char*);
	if (s == NULL)
		s = "(null)";
	if ((f->ip == 0) && (f->p == '2') && (f->l == 0))
		return (0);
	if ((f->ip == 0) && (f->p == '2') && (f->l != 0))
		return ((d += print_j(' ', f->l, 0)));
	size = ft_putstr(s, 0, f->ip);
	if ((!(ft_find('-', f->i))) && f->l > 0 && (!ft_find('0', f->i)))
		d += print_j(' ', f->l, size);
	if (ft_find('0', f->i) && (!(ft_find('-', f->i))))
		d += print_j('0', f->l, size);
	a += ft_putstr(s, 1, f->ip);
	if (ft_find('-', f->i) && f->l > 0)
		d += print_j(' ', f->l, size);
	return (a + d);
}

int		ft_putstr(char *s, char y, size_t n)
{
	size_t		i;

	i = 0;
	while (s[i] && ((i < n) || (n <= 0)))
	{
		if (y == 1)
			write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int		ft_putchar(int c, char y)
{
	if (y == 1)
		return (write(1, &c, 1));
	return (1);
}
