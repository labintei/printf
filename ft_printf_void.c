/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:56:48 by labintei          #+#    #+#             */
/*   Updated: 2021/03/01 14:05:13 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	libere_s(char *s)
{
	int		i;

	i = 0;
	while(s[i] && s[i] != 0)
	{
		s[i] = 0;
		i++;
	}
	return ;
}

void	ft_init_flags(struct f_flags *f)
{
	libere_s(f->indicateur);
	f->largeur= 0;
	f->precision = 0;
	f->intprecision = -1;
	f->type = 0;
	return ;
}

void	ft_init_int(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
	return ;
}

void	ft_define_flags(const char *s, struct f_flags *f, va_list ap)
{
	char c;
	int	 i;
	int	 d;

	d = 0;
	i = ft_indicateur(f, (char *)s);
	f->intprecision = 0;
	while(s[i] && (c = ft_find(s[i],"0123456789")))
	{
		f->largeur = (f->largeur * 10) + (c - '0');
		i++;
	}
	if(s[i] && ((ft_find(s[i],".") || ft_find(s[i],"*"))))
		ft_precision(s, &i, f, ap);
	if(s[i] && ((ft_find(s[i],"0"))))
	{
		while((f->indicateur)[d])
			d++;
		(f->indicateur)[d] = 'a';
		(f->indicateur)[++d] = '\0';
	}
	while(s[i] && (c = ft_find(s[i], "0123456789")) && (!(ft_find('P',f->indicateur))))
	{
		f->intprecision = (f->intprecision * 10) + (c - '0');
		i++;
	}
	if(s[i] && (ft_find(s[i], "cspdiuXx%")))
		f->type = s[i];
	return ;
}
