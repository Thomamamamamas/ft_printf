/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:48:45 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/02 18:11:08 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	parse_conversion(int conversion, va_list arguments)
{
	char	*str;
	int		len;

	if (conversion == 'd' || conversion == 'i')
		str = di_conversion(arguments);
	else if (conversion == 'c')
	{
		c_conversion(arguments);
		return (1);
	}
	else if (conversion == 's')
		str = s_conversion(arguments);
	else if (conversion == 'x' || conversion == 'p' || conversion == 'X')
		str = pxX_conversion(arguments, conversion);
	else if (conversion == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	len = ft_strlen(str);
	if (conversion == 'p')
		len += 2;
	if (conversion != '%')
		free(str);
	return (len);
}
