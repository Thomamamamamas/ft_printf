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
#include <stdlib.h>

void	parse_conversion(int conversion, va_list arguments)
{
	char	*str;

	if (conversion == 'd' || conversion == 'i')
		ft_putstr_fd(ft_itoa(va_arg(arguments, int)), 1);
	else if (conversion == 'c')
		ft_putchar_fd(va_arg(arguments, int), 1);
	else if (conversion == 's')
		ft_putstr_fd(va_arg(arguments, char *), 1);
	else if (conversion == 'X')
		ft_putstr_fd(ft_itoa_base(va_arg(arguments, int), 16), 1);
	else if (conversion == 'x' || conversion == 'p')
	{
		str = ft_itoa_base(va_arg(arguments, long), 16);
		if (conversion == 'p')
			ft_putstr_fd("0x", 1);
		while (*str)
			ft_putchar_fd(ft_tolower(*str++), 1);
		if (str)
			free(str);
	}
	else if (conversion == '%')
		ft_putchar_fd('%', 1);
}
