/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:08:03 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/11 20:08:39 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	parse_conversion(int conversion, va_list arguments)
{
	int	len;

	len = 0;
	if (conversion == 'd' || conversion == 'i')
		len = ft_putnbr(va_arg(arguments, int));
	if (conversion == 'c')
		len = ft_putchar(va_arg(arguments, int));
	else if (conversion == 's')
		len = ft_putstr(va_arg(arguments, char *));
	else if (conversion == 'p')
	{
		len += ft_putstr("0x");
		len += ft_put_address(va_arg(arguments, unsigned long long));
	}
	else if (conversion == 'x')
		len = ft_putnbr_hexa_lower(va_arg(arguments, unsigned int));
	else if (conversion == 'X')
		len = ft_putnbr_hexa(va_arg(arguments, unsigned int));
	else if (conversion == 'u')
		len = ft_putnbr_unsigned(va_arg(arguments, int));
	else if (conversion == '%')
		len = ft_putchar('%');
	return (len);
}
