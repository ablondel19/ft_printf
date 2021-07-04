# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/18 19:38:50 by ablondel          #+#    #+#              #
#    Updated: 2020/12/22 11:35:18 by ablondel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c \
ft_conv_c.c \
ft_conv_s.c \
ft_conv_d.c \
ft_conv_p.c \
ft_conv_u.c \
ft_conv_x.c \
ft_flag_read.c \
ft_flagdup.c \
ft_utils.c \
ft_hex.c \
ft_init.c \
ft_nbrlen.c \
ft_nbulen.c \
ft_printf.c \
ft_putaddr.c \
ft_putchar.c \
ft_putnbr.c \
ft_putstr.c \
ft_putu.c \
ft_strdup.c \
ft_strlen.c \
ft_hexlen.c \
ft_limit.c \

OBJ = ${SRC:.c=.o}

NAME = libftprintf.a

LINK = ar rc

$(NAME):		$(OBJ)
	$(LINK)		$(NAME) 	$(OBJ)

all:		$(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re
