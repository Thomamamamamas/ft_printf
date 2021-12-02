/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:09:16 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/02 18:12:09 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		ft_putstr_fd("(null)", 1);
		str = ft_strdup("(null)");
		return (str);
	}
	str = ft_strdup(tmp);
	ft_putstr_fd(str, 1);
	return (str);
}

char	*pxX_conversion(va_list arguments, int conversion)
{
	char		*str;
	unsigned long long	tmp;
	size_t		n;

	n = 0;

	tmp = va_arg(arguments, unsigned long long);
	str = ft_ull_base(tmp, 16);
	if (conversion == 'x' || conversion == 'p')
	{
		if (conversion == 'p')
		{
			ft_putstr_fd("0x", 1);
			if (tmp == 0)
			{
				ft_putchar_fd('0', 1);
				str = ft_strdup("0");
				return (str);
			}
		}
		while (str[n])
		{
			ft_putchar_fd(ft_tolower(str[n]), 1);
			n++;
		}
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
	char	*str;

	str = ft_itoa(va_arg(arguments, unsigned int));
	ft_putstr_fd(str, 1);
	return (str);
}
