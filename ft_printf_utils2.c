/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:54:18 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/11 11:03:47 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_address(unsigned long long n)
{
	char	*caracters;
	int		len;

	caracters = "0123456789abcdef";
	len = 0;
	if (n >= 16)
	{
		len += ft_put_address((n / 16));
		len += ft_putchar(caracters[n % 16]);
	}
	else
		len += ft_putchar(caracters[n % 16]);
	return (len);
}

int	ft_putnbr_hexa(long long n)
{
	char	*caracters;
	int		len;

	caracters = "0123456789ABCDEF";
	len = 0;
	if (n >= 16)
	{
		len += ft_putnbr_hexa((n / 16));
		len += ft_putchar(caracters[n % 16]);
	}
	else
		len += ft_putchar(caracters[n % 16]);
	return (len);
}

int	ft_putnbr_hexa_lower(long long n)
{
	char	*caracters;
	int		len;

	caracters = "0123456789abcdef";
	len = 0;
	if (n >= LONG_MAX)
		return (ft_putstr("ffffffff"));
	if (n >= 16)
	{
		len += ft_putnbr_hexa_lower((n / 16));
		len += ft_putchar(caracters[n % 16]);
	}
	else
		len += ft_putchar(caracters[n % 16]);
	return (len);
}
