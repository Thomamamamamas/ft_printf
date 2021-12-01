/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:17:23 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/20 16:35:01 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *content, ...)
{
	va_list	arguments;
	size_t		n;

	va_start(arguments, content);
	n = 0;
	while (content[n])
	{
		if (content[n] == '%')
		{
			n++;
			parse_conversion(content[n], arguments);
		}
		else
			ft_putchar_fd(content[n], 1);
		n++;
	}
	va_end(arguments);
	return (0);
}
