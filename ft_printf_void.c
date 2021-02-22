/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:56:48 by labintei          #+#    #+#             */
/*   Updated: 2021/02/22 11:53:55 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	libere_s(char *s)
{
	while(*s)
	{
		*s = '\0';
		s++;
	}
	return ;
}

void	ft_init_flags(struct f_flags *f)
{
	libere_s(f->indicateur);
	f->largeur= 0;
	f->precision = 0;
	f->intprecision = 0;
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

char	ft_precision(const char *s, int *i)
{
	char	z;

	z = 0;
	while(s[(*i)] && ft_find(s[(*i)], "*"))
	{	
		if(z == 0)
			z = 1;
		(*i)++;
	}
	while(s[(*i)] && ft_find(s[(*i)],"."))
	{
		if(z == 0 || z == 1)
			z += 2;
		(*i)++;
	}
	while(s[(*i)] && ft_find(s[(*i)],"*"))
	{
		if(z == 2 || z == 3)
				z += 3;
		(*i)++;
	}
	return(z + '0');
}

void	ft_define_flags(const char *s, struct f_flags *f)
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
		f->precision = ft_precision(s, &i);
	if(s[i] && ((ft_find(s[i],"0"))))
	{
		while((f->indicateur)[d])
			d++;
		(f->indicateur)[d] = 'a';
		(f->indicateur)[++d] = '\0';
	}
	while(s[i] && (c = ft_find(s[i], "0123456789")))
	{
		f->intprecision = (f->intprecision * 10) + (c - '0');
		i++;
	}
	if(s[i] && (ft_find(s[i], "cspdiuXx%")))
		f->type = s[i];
	return ;
}
