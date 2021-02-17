/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_charstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:55:23 by labintei          #+#    #+#             */
/*   Updated: 2021/02/17 14:33:49 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr(char *s,char y,size_t n)
{
	size_t		i;

	i = 0;
	while(s[i] && ((i < n) || (n == 0)))
	{
		if(y == 1)
			write(1, &s[i], 1);
		i++;
	}
	return(i);
}

int		ft_putchar(int c, char y)
{
	if(y == 1)
		return(write(1, &c, 1));
	return(1);
}
