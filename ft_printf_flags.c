/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:41:57 by labintei          #+#    #+#             */
/*   Updated: 2021/03/01 15:49:00 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void		ajout_indicateur(char c, char *s)
{
	int		n;

	n = 0;
	if(!(ft_find(c, s)))
	{
		while(s[n])
			n++;
		s[n] = c;
		s[++n] = '\0';
	}
	return		;
}

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
		ajout_indicateur('L',f->indicateur);
		if(j < 0)
		{
			ajout_indicateur('-',f->indicateur);
			ajout_indicateur('a',f->indicateur);
			f->largeur = -j;
		}
		else
		{
			f->largeur = j;
		}
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
		ajout_indicateur('P',f->indicateur);
		j = va_arg(ap, int);
		if(j < 0)
		{
			f->intprecision = -2;
		}
		else
			f->intprecision = j;
	}
	while(s[(*i)] && ft_find(s[(*i)], "*"))
		(*i)++;
	if((ft_find('L',f->indicateur) && (f->precision == '2') && (f->intprecision != -2)))
	{
		y = 0;
		while(f->indicateur[y] && f->indicateur[y] != '0')
			y++;
		if(f->indicateur[y] == '0')
			f->indicateur[y] = 's';
	}
}
