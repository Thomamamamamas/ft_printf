/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:24:30 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/02 17:37:48 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
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
	len_faux = ft_printf(" %x ", m);
	printf("return vrai printf : %d", len_vrai);
	printf("return faux printf : %d", len_faux);
	return (0);
}*/

int main(int ac , char **av)
{

	int i = 0;

	printf("Ret V = %d\n", printf("\nI== %p\n", i));
	printf("Ret F = %d\n", ft_printf("\nI== %p\n", i));
}













