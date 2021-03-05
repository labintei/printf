/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:43:17 by labintei          #+#    #+#             */
/*   Updated: 2021/03/05 10:26:35 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct	s_flags
{
	char			i[16];
	int				l;
	char			p;
	int				ip;
	char			type;
}				t_flags;

void			libere_s(char *s);
void			ft_init_flags(struct s_flags *f);
void			ft_init_int(int *a, int *b, int *c);
int				ft_indicateur(struct s_flags *f, char *s);
void			ft_define_flags(const char *s, struct s_flags *f, va_list ap);
int				ft_print_flags(struct s_flags *l, va_list ap);
int				ft_printf_type(char t, char y, va_list ap);
char			ft_find(const char c, const char *s);
int				ft_taille_flags(const char *s);
int				print_flags(const char *s, va_list ap, ...);
int				ft_printf(const char *s, ...);
int				ft_unsigned(unsigned int n, char z);
int				ft_putchar(int n, char y);
int				ft_putstr(char *s, char y, size_t n);
int				basehexa(unsigned int n, char a, char y);
int				basehexa_bis(unsigned long long n, char a, char y);
int				print_int(long int n, char y);
int				print_p(struct s_flags *f, void *c, char y);
void			ft_precision(const char *s, int *i, struct s_flags *f,
				va_list ap);
void			ft_prec_bis(const char *s, int *i, struct s_flags *f,
				va_list ap);
int				ft_print_type_c(struct s_flags *f, va_list ap, ...);
int				ft_print_type_s(struct s_flags *f, va_list ap, ...);
int				ft_print_type_p(struct s_flags *f, va_list ap, ...);
int				ft_print_type_di(struct s_flags *f, va_list ap, ...);
int				ft_print_type_x(struct s_flags *f, va_list ap, ...);
int				ft_print_type_u(struct s_flags *f, va_list ap, ...);
int				ft_print_type_modulo(struct s_flags *f);
int				print_j(char c, int a, int b);
int				size_int(long int n, int sizebase);
int				size_int_hexa(unsigned int n, unsigned int sizebase);
int				size_int_hexa_bis(unsigned long long i, unsigned long
				long int size);
void			ft_prec_bis(const char *s, int	*i, struct s_flags *f,
				va_list ap);
int				init(struct s_flags *f, int n, int z, char y);
int				ft_di(long int *l);
int				ft_di_bis(struct s_flags *f, int neg, int size, char y);
void			ajout_indicateur(char c, char *s);

#endif
