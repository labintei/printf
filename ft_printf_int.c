/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:03:41 by labintei          #+#    #+#             */
/*   Updated: 2021/03/02 15:04:19 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unsigned(unsigned int n, char y)
{
	int		i;
	int		b;
	int		ret;
	long	long	 int	a;
	char			*s;

	(n < 0) ? (a = n + 4294967296) : (a = n);
	if(!(s = malloc(sizeof(char) * ((i = size_int((long int)a, 10)) + 1))))
		return(0);
	s[i] = '\0';
	b = i;
	ret = 0;
	while(--i >= 0)
	{
		s[i] = (a % 10) + '0';
		a /= 10;
	}
	while(++i != b)
		ret += ft_putchar(s[i], y);
	libere_s(s);
	free(s);
	return(ret);
}

int		size_int(long int n, int sizebase)
{
	long int	i;
	int			size;

	(n < 0) ? (size = 1) : (size = 0);
	(n < 0) ? (i = -n) : (i = n);
	while(i >= sizebase && ++size)
		i /= sizebase;
	return(size + 1);
}

int		size_int_hexa(unsigned int n, unsigned int sizebase)
{
	int		size;

	size = 0;
	while(n	 > sizebase && ++size)
		n /= sizebase;
	return(size + 1);
}

int		basehexa(unsigned int n, char a, char y)
{
	unsigned int	c;
	int				i;
	char			*s;
	char			*res;
	int				ret;
	int				g;

	ret = 0;
	i = 0;
	s = "0123456789abcdef";
	c = n;
	g = size_int_hexa(c, 16);
	if(!(res = malloc(sizeof(char) * (g + 1))))
		return(0);
	res[g] = '\0';
	i = g-1;
	while(i >= 0)
	{
		res[i] = s[(c % 16)];
		if(a == 1 && (res[i] >= 'a' && res[i] <= 'z'))
			res[i] -= 32;
		c /= 16;
		i--;
	}
	while(++i != g)
		ret += ft_putchar(res[i], y);
	libere_s(res);
	free(res);
	return(ret);
}

int		size_int_hexa_bis(unsigned long long i, unsigned long long int sizebase)
{
	int		size;

	size = 0;
	while(i >= sizebase && ++size)
		i /= sizebase;
	return(size + 1);
}

int		basehexa_bis(unsigned long long  n, char a, char y)
{
	unsigned long long	c;
	int				i;
	char			*s;
	char			*res;
	int				ret;
	int				g;

	ret = 0;
	i = 0;
	s = "0123456789abcdef";
	c = n;
	g = size_int_hexa_bis(c, 16);
	if(!(res = malloc(sizeof(char) * (g + 1))))
		return(0);
	res[g] = '\0';
	i = g;
	while(--i >= 0)
	{
		res[i] = s[(c % 16)];
		if(a == 1 && (res[i] >= 'a' && res[i] <= 'z'))
			res[i] -= 32;
		c /= 16;
	}
	while(++i != g)
		ret += ft_putchar(res[i], y);
	libere_s(res);
	free(res);
	return(ret);
}


int		print_int(long int n, char y)
{
	long	int g;
	int		i;
	int		a;
	char	*res;
	int		ret;

	ret = 0;
	(n < 0) ? (g = -n) : (g = n);
	if(!(res = malloc((sizeof(char) * ((i = size_int((long int)n, 10))+ 1)))))
		return(0);
	res[i] = '\0';
	if(n < 0)
		ret += ft_putchar('-', 1);
	a = i;
	while(--i >= 0)
	{
		res[i] = (g % 10) + '0';
		g /= 10;
	}
	while(++i != a)
		ret += ft_putchar(res[i], y);
	libere_s(res);
	free(res);
	return(a);
}

int		print_p(void *i, char y)
{
	unsigned long long	 	c;
	int					f;

	f = 0;
	c = (unsigned long long)i;
	f += basehexa_bis(c, 0, y);
	return(f);
}
