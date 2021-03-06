/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_define.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:02:02 by labintei          #+#    #+#             */
/*   Updated: 2021/03/06 16:22:40 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		size_int_hexa_bis(unsigned long long i, unsigned long long int sizebase)
{
	int		size;

	size = 0;
	while (i >= sizebase && ++size)
		i /= sizebase;
	return (size + 1);
}

int		print_j(char c, int i, int start)
{
	int		j;

	j = 0;
	if (start >= i)
		return (0);
	--start;
	while (++start < i)
		j += ft_putchar((int)c, 1);
	return (j);
}

int		ft_taille_flags(const char *s)
{
	int		i;
	char	j;

	i = 1;
	j = 0;
	while (s[i] && j == 0)
	{
		while (s[i] && (ft_find(s[i], "-0")))
			i++;
		while (s[i] && (ft_find(s[i], "0123456789")))
			i++;
		while (s[i] && ft_find(s[i], ".*"))
			i++;
		while (s[i] && (ft_find(s[i], "0123456789")))
			i++;
		if (s[i] && (ft_find(s[i], "cspdiuXx%")))
			i++;
		j = 1;
	}
	if (!(ft_find(s[i - 1], "cspdiuXx%")))
		return (-1);
	return (i);
}

char	ft_find(const char c, const char *s)
{
	while (*s)
	{
		if (*s && c == *s)
			return ((char)c);
		s++;
	}
	return (0);
}

int		ft_indicateur(struct s_flags *f, char *s)
{
	int		i;
	int		j;
	int		y;

	ft_init_int(&i, &j, &y);
	while (s[i] && ((ft_find(s[i], "0")) || (ft_find(s[i], "-"))))
		i++;
	y--;
	while (s[j] && j < i)
	{
		if ((!(ft_find('-', f->i))) && ft_find(s[j], "-"))
			(f->i)[++y] = '-';
		if ((!(ft_find('0', f->i))) && ft_find(s[j], "0"))
			(f->i)[++y] = '0';
		j++;
	}
	return (i);
}
