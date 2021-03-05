/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:44:03 by labintei          #+#    #+#             */
/*   Updated: 2021/03/05 10:26:57 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	libere_s(char *s)
{
	int		i;

	i = -1;
	while (s[++i] && s[i] != 0)
		s[i] = 0;
	return ;
}

void	ft_init_int(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
	return ;
}

void	ft_define_flags(const char *s, struct s_flags *f, va_list ap)
{
	int		i;
	int		d;

	d = 0;
	i = ft_indicateur(f, (char *)s);
	f->ip = 0;
	--i;
	while (s[++i] && (ft_find(s[i], "0123456789")))
		f->l = (f->l * 10) + (s[i] - '0');
	if (s[i] && ((ft_find(s[i], ".")) || (ft_find(s[i], "*"))))
		ft_precision(s, &i, f, ap);
	if (s[i] && ((ft_find(s[i], "0"))))
	{
		while ((f->i)[d])
			d++;
		(f->i)[d] = 'a';
		(f->i)[++d] = '\0';
	}
	--i;
	while (s[++i] && (ft_find(s[i], "0123456789")) && (!(ft_find('P', f->i))))
		f->ip = (f->ip * 10) + (s[i] - '0');
	if (s[i] && (ft_find(s[i], "cspdiuXx%")))
		f->type = s[i];
	return ;
}

int		print_flags(const char *s, va_list ap, ...)
{
	struct s_flags	l;
	int				n;
	char			c;

	c = 1;
	n = 0;
	ft_init_flags(&l);
	ft_define_flags(++s, &l, ap);
	if (l.type == 'c')
		return (ft_print_type_c(&l, ap));
	if (l.type == 's')
		return (ft_print_type_s(&l, ap));
	if (l.type == 'p')
		return (ft_print_type_p(&l, ap));
	if (l.type == 'd' || l.type == 'i')
		return (ft_print_type_di(&l, ap));
	if (l.type == 'u')
		return (ft_print_type_u(&l, ap));
	if (l.type == 'x' || l.type == 'X')
		return (ft_print_type_x(&l, ap));
	if (l.type == '%')
		return (ft_print_type_modulo(&l));
	return (0);
}

int		ft_printf(const char *s, ...)
{
	int		n;
	int		i;
	int		ret;
	va_list	ap;

	ft_init_int(&n, &i, &ret);
	va_start(ap, s);
	while (s[n])
	{
		while (s[n] && s[n] != '%')
		{
			n += write(1, &s[n], 1);
			ret++;
		}
		if (s[n] == '%')
		{
			i = ft_taille_flags(s + n);
			ret += print_flags(s + n, ap);
			n += i;
		}
	}
	va_end(ap);
	return (ret);
}
