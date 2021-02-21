# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: labintei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 14:05:41 by labintei          #+#    #+#              #
#    Updated: 2021/02/20 10:50:26 by labintei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf.c ft_printf_charstr.c ft_printf_define.c \
				ft_printf_flags.c ft_printf_int.c ft_printf_type.c \
				ft_printf_void.c
OBJS		= $(SRCS:.c=.o)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I.
RM				= rm -f

NAME			= libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:		all clean fclean
