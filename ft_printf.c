/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:17:23 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/06 16:52:33 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *content, ...)
{
	va_list	arguments;
	int		len;
	size_t	n;

	va_start(arguments, content);
	len = 0;
	n = 0;
	while (content[n])
	{
		if (content[n] == '%')
		{
			n++;
			len += parse_conversion(content[n], arguments);
		}
		else
			len += ft_putchar(content[n]);
		n++;
	}
	va_end(arguments);
	return (len);
}
