# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 14:52:20 by tcasale           #+#    #+#              #
#    Updated: 2021/12/11 11:03:06 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	=	ft_printf.c \
			ft_printf_utils.c \
			ft_printf_utils2.c

FLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

%.o:	%.c
	gcc -c ${FLAGS} -o $@ $<

all:	${NAME}

${NAME}:${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	rm -f ${SRCS:.c=.o}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
