/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:48:45 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/20 16:34:59 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	parse_flag(int flag, va_list arguments)
{
	if (flag == 'd')
	{
		ft_putstr_fd(ft_itoa(va_arg(arguments, int)), 1);
	}
	else if (flag == 'c')
	{
		ft_putchar_fd(va_arg(arguments, int), 1);
	}
	else if (flag == 's')
		ft_putstr_fd(va_arg(arguments, char *), 1);
	else if (flag == '%')
		ft_putchar_fd('%', 1);
}
