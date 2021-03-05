/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:41:57 by labintei          #+#    #+#             */
/*   Updated: 2021/03/05 10:27:46 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init_flags(struct s_flags *f)
{
	libere_s(f->i);
	f->l = 0;
	f->p = 0;
	f->ip = -1;
	f->type = 0;
	return ;
}

void		ajout_indicateur(char c, char *s)
{
	int		n;

	n = 0;
	if (!(ft_find(c, s)))
	{
		while (s[n])
			n++;
		s[n] = c;
		s[++n] = '\0';
	}
	return ;
}

void		ft_precision(const char *s, int *i, struct s_flags *f, va_list ap)
{
	int		j;

	j = 0;
	if (s[*i] && ft_find(s[(*i)], "*"))
	{
		j = va_arg(ap, int);
		ajout_indicateur('L', f->i);
		if (j < 0)
		{
			ajout_indicateur('-', f->i);
			ajout_indicateur('a', f->i);
			f->l = -j;
		}
		else
			f->l = j;
	}
	while (s[(*i)] && ft_find(s[(*i)], "*"))
		(*i)++;
	ft_prec_bis(s, i, f, ap);
	return ;
}

void		ft_prec_bis(const char *s, int *i, struct s_flags *f, va_list ap)
{
	int		j;

	if (s[(*i)] && ft_find(s[(*i)], "."))
		f->p = '2';
	while (s[(*i)] && ft_find(s[(*i)], "."))
		(*i)++;
	if (s[*i] && ft_find(s[(*i)], "*"))
	{
		ajout_indicateur('P', f->i);
		j = va_arg(ap, int);
		if (j < 0)
			(f->ip = -2);
		else
			(f->ip = j);
	}
	while (s[(*i)] && ft_find(s[(*i)], "*"))
		(*i)++;
	j = 0;
	if ((ft_find('L', f->i)) && (f->p == '2') && (f->ip != -2))
	{
		while ((f->i)[j] && (f->i)[j] != '0')
			j++;
		(f->i)[j] = ((f->i)[j] == '0') ? 's' : '\0';
	}
	return ;
}

int			size_int(long int n, int sizebase)
{
	long int	i;
	int			size;

	if (n < 0)
		size = 1;
	else
		size = 0;
	if (n < 0)
		i = -n;
	else
		i = n;
	while (i >= sizebase && ++size)
		i /= sizebase;
	return (size + 1);
}
