/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:56:24 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/19 19:25:54 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

void	print_ptfo_value(t_ptfo *po)
{
	printf("sharp = %d\n", po->sharp);
	printf("zero_filled = %d\n", po->zero_filled);
	printf("r_just_value = %d\n", po->r_just_value);
	printf("l_just = %d\n", po->l_just);
	printf("l_just_value = %d\n", po->l_just_value);
	printf("p_sign = %d\n", po->p_sign);
	printf("i_sign = %d\n", po->i_sign);
	printf("conversion = %c\n", po->conversion);
}

int	main()
{
	int	pute;

	pute = 3;
	printf("_____________________________________________________________________________\n");
	printf("len vrai printf = %d\n", printf("vrai printf = %-5d\n", 0));
	printf("_____________________________________________________________________________\n");
	printf("len faux printf = %d\n", ft_printf("faux printf = %-5d\n", 0));
	printf("_____________________________________________________________________________\n");
	
	return (0);
}
