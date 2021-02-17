/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_define.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:02:02 by labintei          #+#    #+#             */
/*   Updated: 2021/02/17 15:51:34 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int		ft_taille_flags(const char *s)
{
	int		i;
	char	j;

	i = 1;
	j = 0;
	while(s[i] && j== 0)
	{
		while(s[i] && (ft_find(s[i], "-0")))
			i++;
		while(s[i] && (ft_find(s[i],"0123456789")))
			i++;
		while(s[i] && ft_find(s[i], ".*"))
			i++;
		while(s[i] && (ft_find(s[i], "0123456789")))
			i++;
		if(s[i] && (ft_find(s[i], "cspdiuXx")))
			i++;
		j = 1;
	}
	if(!(ft_find(s[i - 1], "cspdiuXx")))
		return(-1);
	return(i);
}

char	ft_find(const char c, const char *s)
{
	while(*s)
	{
		if(*s && c == *s)
			return((char)c);
		s++;
	}
	return(0);
}

void	ft_find_char(int y,const char c, const char *s, struct f_flags *f)
{
	if(ft_find(c,s))
	{
		if(!(ft_find(*s,(const char*)f->indicateur)))
			(f->indicateur)[y] = *s;
		y++;
	}
	return ;
}

int		ft_indicateur(struct f_flags *f, char *s)
{
	int		i;
	int		j;
	int		y;

	ft_init_int(&i, &j, &y);
	while(s[i] && (ft_find(s[i], "0-")))
		i++;
	while(s[j] && j < i)
	{
		ft_find_char(y, s[j],"0", f);
		ft_find_char(y, s[j],"-", f);
		j++;
	}
	return(i);
}
