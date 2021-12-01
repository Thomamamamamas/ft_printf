/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:24:30 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/20 16:35:03 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"
#include <stdio.h>

int	main()
{
	int	n;
	int	*m;
	int	*d;

	n = 0xabcd10;
	printf("vrai printf : %c", '0');
	ft_printf("ft_printf : %c", '0');
	return (0);
}
