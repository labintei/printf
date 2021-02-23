/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:41:57 by labintei          #+#    #+#             */
/*   Updated: 2021/02/23 11:15:28 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void		ft_precision(const char *s, int *i, struct f_flags *f, va_list ap)
{
	char	z;
	int		j;
	int		y;

	j = 0;
	z = 0;
	y = 0;
	if(s[*i] && ft_find(s[(*i)], "*"))
	{
		j = va_arg(ap,int);
		if(j < 0)
		{
			if(!(ft_find('-',f->indicateur)))
			{
				while((f->indicateur)[y])
					y++;
				(f->indicateur)[y] = '-';
				(f->indicateur)[++y] = '\0';
			}
			f->largeur = -j;
		}
		else
			f->largeur = j;
	}
	while(s[(*i)] && ft_find(s[(*i)], "*"))
		(*i)++;
	if(s[(*i)] && ft_find(s[(*i)],"."))
		f->precision = '2';
	while(s[(*i)] && ft_find(s[(*i)],"."))
		(*i)++;
	y = 0;
	if(s[*i] && ft_find(s[(*i)], "*"))
	{
		j = va_arg(ap, int);
		if(j < 0)
		{
			if(!(ft_find('-',f->indicateur)))
			{
				while((f->indicateur)[y])
					y++;
				(f->indicateur)[y] = '-';
				(f->indicateur)[++y] = '\0';
			}
			f->intprecision = -1;
		}
		else
			f->intprecision = j;
		z = 2;
	}
	while(s[(*i)] && ft_find(s[(*i)], "*"))
		(*i)++;
}
