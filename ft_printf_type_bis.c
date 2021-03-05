/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:24:53 by labintei          #+#    #+#             */
/*   Updated: 2021/03/05 10:28:28 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_di(long int *l)
{
	if (*l < 0)
	{
		*l *= -1;
		return (ft_putchar('-', 1));
	}
	return (0);
}

int		ft_di_bis(struct s_flags *f, int neg, int size, char y)
{
	int		largeur;
	int		prec;
	int		a;

	a = 0;
	largeur = (f->ip + neg > size) ? f->ip + neg : size;
	prec = (f->ip > 0) ? 1 : 0;
	if (y == 1)
	{
		if ((ft_find('0', f->i) && ((f->p != '2')) && (!(ft_find('-', f->i)))))
			a += print_j('0', f->l, size);
		if (prec == 1 && (f->ip + neg > size))
			a += print_j('0', f->ip + neg, size);
		return (a);
	}
	if (y == 2)
		return (a += (ft_find('-', f->i)) ? print_j(' ', f->l, largeur) : 0);
	return (0);
}

int		ft_unsigned(unsigned int n, char y)
{
	int				i;
	int				b;
	int				ret;
	long long int	a;
	char			*s;

	ret = 0;
	a = (n < 0) ? (n + 4294967296) : (n);
	i = size_int((long int)a, 10);
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (0);
	s[i] = '\0';
	b = i;
	while (--i >= 0)
	{
		s[i] = (a % 10) + '0';
		a /= 10;
	}
	while (++i != b)
		ret += ft_putchar(s[i], y);
	libere_s(s);
	free(s);
	return (ret);
}
