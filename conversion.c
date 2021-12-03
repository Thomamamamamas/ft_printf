/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:09:16 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/03 14:36:59 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	c_conversion(va_list arguments)
{
	ft_putchar_fd(va_arg(arguments, int), 1);
}

char	*s_conversion(va_list arguments)
{
	char	*str;
	char	*tmp;

	tmp = va_arg(arguments, char *);
	if (!tmp)
	{
		str = ft_strdup("(null)");
		ft_putstr_fd(str, 1);
		return (str);
	}
	str = ft_strdup(tmp);
	ft_putstr_fd(str, 1);
	return (str);
}

char	*pxX_conversion(va_list arguments, int conversion)
{
	char				*str;
	unsigned long long	tmp;
	size_t				n;

	n = 0;
	tmp = va_arg(arguments, unsigned long long);
	if (conversion == 'p')
	{
		str = ft_itoa_hexa(tmp);
		ft_putstr_fd("0x", 1);
	}
	else if (tmp >= ULONG_MAX)
		str = ft_strdup("FFFFFFFF");
	else
		str = ft_itoa_unsigned_hexa(tmp);
	if (conversion == 'x' || conversion == 'p')
	{
		while (str[n])
			ft_putchar_fd(ft_tolower(str[n++]), 1);
	}
	else
		ft_putstr_fd(str, 1);
	return (str);
}

char	*di_conversion(va_list arguments)
{
	char	*str;

	str = ft_itoa(va_arg(arguments, int));
	ft_putstr_fd(str, 1);
	return (str);
}

char	*u_conversion(va_list arguments)
{
	char			*str;
	unsigned int	tmp;

	tmp = va_arg(arguments, int);
	if (tmp < 0)
		tmp = tmp + UINT_MAX - 1;
	str = ft_itoa_unsigned(tmp);
	ft_putstr_fd(str, 1);
	return (str);
}
