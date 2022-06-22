/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:59:59 by tcasale           #+#    #+#             */
/*   Updated: 2022/06/22 18:39:45 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

void	print_ptfo_value(t_ptfo *po)
{
	printf("sharp = %d\n", po->sharp);
	printf("zero_filled = %d\n", po->zero_filled);
	printf("dot = %d\n", po->dot);
	printf("r_just_value = %d\n", po->r_just_value);
	printf("l_just = %d\n", po->l_just);
	printf("l_just_value = %d\n", po->l_just_value);
	printf("p_sign = %d\n", po->p_sign);
	printf("i_sign = %d\n", po->i_sign);
	printf("conversion = %c\n", po->conv);
}

int	main()
{
	printf("_____________________________________________________________________________\n");
	printf("len vrai printf = %d\n", printf("vrai printf = %03d\n", -11));
	printf("_____________________________________________________________________________\n");
	printf("len faux printf = %d\n", ft_printf("faux printf = %03d\n", -11));
	printf("_____________________________________________________________________________\n");
	return (0);
}
