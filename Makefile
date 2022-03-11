# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 14:52:20 by tcasale           #+#    #+#              #
#    Updated: 2022/03/11 20:13:00 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= libftprintf.a

SRCS	=	ft_printf.c \
			ft_printf_utils.c

OBJS		= ${SRCS:.c=.o}

HEADER	= includes

CC		= gcc
RM		= rm -f
AR		= ar rcs

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
			${CC} -c ${CFLAGS} -I./Libft -o $@ $<

all: $(NAME)


$(NAME):	libft ${OBJS}
			$(AR) ${NAME} $(OBJS)

libft:
	$(MAKE) -C ./Libft bonus
	cp libft/libft.a $(NAME)

clean:
		$(MAKE) -C ./Libft $@
		${RM} ${OBJS}

fclean:	clean
		$(MAKE) -C ./Libft $@
		${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re libft
