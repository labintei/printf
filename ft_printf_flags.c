/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:41:57 by labintei          #+#    #+#             */
/*   Updated: 2021/02/17 15:50:12 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void		ft_precision_f(char p, struct f_flags *f, va_list ap)
{
	if(p == '3' || p == '6')
		f->largeur = va_arg(ap, int);
	if(p == '5' || p == '6')
		f->intprecision = va_arg(ap, int);
	return	;
}
