/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:03:41 by labintei          #+#    #+#             */
/*   Updated: 2021/03/06 16:23:03 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		size_int_hexa(unsigned int n, unsigned int sizebase)
{
	int		size;

	size = 0;
	while (n > sizebase && ++size)
		n /= sizebase;
	return (size + 1);
}

int		basehexa(unsigned int n, char a, char y)
{
	int				i;
	char			*s;
	char			*res;
	int				g;

	i = 0;
	s = "0123456789abcdef";
	g = size_int_hexa(n, 16);
	if (!(res = malloc(sizeof(char) * (g + 1))))
		return (0);
	res[g] = '\0';
	i = g;
	while (--i >= 0)
	{
		res[i] = s[(n % 16)];
		if (a == 1 && (res[i] >= 'a' && res[i] <= 'z'))
			res[i] -= 32;
		n /= 16;
	}
	while (++i != g)
		ft_putchar(res[i], y);
	libere_s(res);
	free(res);
	return (i);
}

int		basehexa_bis(unsigned long long n, char a, char y)
{
	int				i;
	char			*s;
	char			*res;
	int				g;

	s = "0123456789abcdef";
	g = size_int_hexa_bis(n, 16);
	if (!(res = malloc(sizeof(char) * (g + 1))))
		return (0);
	res[g] = '\0';
	i = g;
	while (--i >= 0)
	{
		res[i] = s[(n % 16)];
		if (a == 1 && (res[i] >= 'a' && res[i] <= 'z'))
			res[i] -= 32;
		n /= 16;
	}
	while (++i != g)
		ft_putchar(res[i], y);
	libere_s(res);
	free(res);
	return (i);
}

int		print_int(long int n, char y)
{
	long	int g;
	int			i;
	int			a;
	char		*res;

	g = (n < 0) ? -n : n;
	i = size_int((long int)n, 10);
	if (!(res = malloc((sizeof(char) * (i + 1)))))
		return (0);
	res[i] = '\0';
	if (n < 0)
		ft_putchar('-', 1);
	a = i;
	while (--i >= 0)
	{
		res[i] = (g % 10) + '0';
		g /= 10;
	}
	while (++i != a)
		ft_putchar(res[i], y);
	if (n < 0)
		i++;
	libere_s(res);
	free(res);
	return (i);
}

int		print_p(struct s_flags *g, void *i, char y)
{
	unsigned long long		c;
	int						a;
	int						size;

	a = 0;
	c = (unsigned long long)i;
	size = basehexa_bis(c, 0, 0);
	if (i == NULL)
	{
		a += ft_putstr("0x", y, 0);
		if (g->ip > size)
			a += (y == 1) ? print_j('0', g->ip, size) : (g->ip - size);
		a += (g->ip <= 0 && g->p == '2') ? 0 : (ft_putstr("0", y, 0));
		return (a);
	}
	a += ft_putstr("0x", y, 0);
	if (g->ip > size)
		a += (y == 1) ? print_j('0', g->ip, size) : (g->ip - size);
	a += basehexa_bis(c, 0, y);
	return (a);
}
