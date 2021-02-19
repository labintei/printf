/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:41:57 by labintei          #+#    #+#             */
/*   Updated: 2021/02/19 09:52:56 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void		ft_precision_f(struct f_flags *f, va_list ap)
{
	if(f->precision == '3' || f->precision == '6')
		f->largeur = va_arg(ap, int);
	if(f->precision == '5' || f->precision == '6')
		f->intprecision = va_arg(ap, int);
	printf("\nLARGEUR :%d INTPRECISON %d",f->largeur, f->intprecision);
	return	;
}
