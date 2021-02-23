/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:43:17 by labintei          #+#    #+#             */
/*   Updated: 2021/02/23 15:00:32 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_PRINTF_H
#define		FT_PRINTF_H

#include<stdarg.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

typedef	struct	f_flags
{
	char	indicateur[16];
	int		largeur;
	char	precision;
	int		intprecision;
	char	type;
}f_flags;

void	libere_s(char *s);
void	ft_init_flags(struct f_flags *f);
void	ft_init_int(int *a, int *b, int *c);

int		ft_indicateur(struct f_flags *f, char *s);
void	ft_define_flags(const char *s, struct f_flags *f, va_list ap);

int		ft_print_flags(struct f_flags *l, va_list ap);
int		ft_printf_type(char t,char y, va_list ap);

char	ft_find(const char c, const char *s);
int		ft_taille_flags(const char *s);
int		print_flags(const char *s, va_list ap, ...);
int		ft_printf(const char *s, ...);

int		ft_print_largeur_diuXx(struct f_flags *f, int size);

int		ft_unsigned(unsigned int n, char z);
int		size_int(long int n, int sizebase);
int		ft_putchar(int n, char y);
int		ft_putstr(char *s, char y, size_t n);
int		basehexa(unsigned long  n, char a, char y);
int		print_int(long int n, char y);
int		print_p(void *c, char y);

int		ft_print_type(struct f_flags *f, va_list ap, ...);
void	ft_precision(const char *s, int *i,struct f_flags *f, va_list ap);

int		ft_dup(char *s, char *s2, int n);

#endif
