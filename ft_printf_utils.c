/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:48:45 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/11 11:03:32 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

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

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	n;
	int	len;

	len = 0;
	if (!s)
		return (ft_putstr("(null)"));
	n = 0;
	while (s[n])
	{
		len += ft_putchar(s[n]);
		n++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	long long int	lln;
	int				len;

	lln = n;
	len = 0;
	if (lln < 0)
	{
		len += ft_putchar('-');
		lln = lln * -1;
	}
	if (lln > 9)
	{
		len += ft_putnbr(lln / 10);
		lln = lln % 10;
	}
	len += ft_putchar(lln + '0');
	return (len);
}

int	ft_putnbr_unsigned(int n)
{
	unsigned int	nb;
	int				len;

	len = 0;
	if (n < 0)
		nb = n + UINT_MAX + 1;
	else
		nb = n;
	if (nb > 9)
	{
		len += ft_putnbr_unsigned(nb / 10);
		nb = nb % 10;
	}
	len += ft_putchar(nb + '0');
	return (len);
}
