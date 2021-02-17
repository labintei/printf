/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:15:46 by labintei          #+#    #+#             */
/*   Updated: 2021/02/17 14:13:46 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<stdio.h>

int			main(void)
{
	struct	f_flags	f;
	int		i;
	int		*p;
	const char	*s;

	s = "01234.....56789c";
	ft_define_flags(s, &f);
	printf("indicateur : %s\n",f.indicateur);
	printf("largeur : %i\n", f.largeur);
	printf("precision : %c\n", f.precision);
	// 1 correspond a * || 2 corespond a . || 3 correspond a *. || 5 correspond a .* || 6 correspond a *.*
	printf("intprecision : %d\n", f.intprecision);
	printf("type : %c\n", f.type);

	ft_init_flags(&f);
	ft_indicateur(&f, "00***---");
	i = 1;
	printf("SIZE INT %d\n", size_int(256489, 16));
	basehexa(-123456789,1,1);
	printf("\n%X\n\n", -123456789);
	print_p(i);
	printf("\n%p\n",&i);
	return(1);
}
