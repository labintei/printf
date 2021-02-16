/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:15:46 by labintei          #+#    #+#             */
/*   Updated: 2021/02/16 12:05:20 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<stdio.h>

int			main(void)
{
	struct	f_flags	f;
	int		i;
	const char	*s;
	s = "0*1234.56789c";
	ft_define_flags(s, &f);
	printf("indicateur : %s\n",f.indicateur);
	printf("largeur : %i\n", f.largeur);
	printf("precision : %c\n", f.precision);
	printf("intprecision : %d\n", f.intprecision);
	printf("type : %c\n", f.type);

	ft_init_flags(&f);
	ft_indicateur(&f, "00***---");
	i = 1;
	return(1);
}
