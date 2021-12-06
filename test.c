/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:24:30 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/06 16:38:26 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
/*
int	main()
{
	int	len_vrai;
	int	len_faux;

	int	n;
	int	m;
	int	*d;

	n = 1;
	m = 0xad5;
	len_vrai = printf(" %x ", m);
NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

OBJS = ${FCTS:.c=.o}

%.o:	%.c
	gcc -c ${FLAGS} -o $@ $<

all:	${NAME}

${NAME}:${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	rm -f ${FCTS:.c=.o}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re	len_faux = ft_printf(" %x ", m);
	printf("return vrai printf : %d", len_vrai);
	printf("return faux printf : %d", len_faux);
	return (0);
}*/

int main(int ac , char **av)
{
	int i = 42;


	printf("Ret V = %d\n", printf(" %x ", ULONG_MAX));
	printf("Ret F = %d\n", ft_printf(" %x ", ULONG_MAX));
}
