/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:24:53 by labintei          #+#    #+#             */
/*   Updated: 2021/03/06 16:21:33 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
