/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:03:41 by labintei          #+#    #+#             */
/*   Updated: 2021/02/23 15:00:19 by labintei         ###   ########.fr       */
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
	if(!(s = malloc(sizeof(char) * ((i = size_int((long int)a, 10) + 1)))))
		return(0);
	b = i;
	ret = i;
	++i;
	while(--i)
	{
		s[i] = (a % 10) + '0';
		a /= 10;
	}
	++i;
	while(++i != ret + 1)
		ft_putchar(s[i], y);
	libere_s(s);
	free(s);
	return(b - 1);
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

int		basehexa(unsigned long n, char a, char y)
{
	long long int	g;
	long long int	c;
	long long int	i;
	char			*s;
	char			*res;

	s = "0123456789abcdef";
	if(!(res = malloc(sizeof(char) * ((g = (size_int(n, 16) + 1))))))
		return(0);
	res[g + 1] = '\0';
	(n < 0) ? (c = 4294967296 + n) : (c = n);
	i = g;
	while(--i)
	{
		res[i] = s[(c % 16)];
		if(a == 1 && (res[i] >= 'a' && res[i] <= 'z'))
			res[i] -= 32;
		c /= 16;
	}
	while(++i != g)
		ft_putchar(res[i], y);
	libere_s(res);
	free(res);
	return (g - 1);
}

int		print_int(long int n, char y)
{
	long	int g;
	int		i;
	int		a;
	char	*res;

	if(!(res = malloc(sizeof(char) * ((i = size_int((long int)n, 10)) + 1))))
		return(0);
	(n < 0) ? (g = -n) : (g = n);
	if(n < 0)
		ft_putchar('-', 1);
	a = i;
	++i;
	while(--i)
	{
		res[i] = (g % 10) + '0';
		g /= 10;
	}
	i++;
	if(n < 0)
		i++;
	while(i != a + 1)
	{
		ft_putchar(res[i], y);
		i++;
	}
	libere_s(res);
	free(res);
	return(a);
}

int		print_p(void *c, char y)
{
	int		i;
	unsigned long	z;

	i = 0;
	z = (unsigned long)c;
	i += basehexa(z, 0, y);
	return(i);
}
