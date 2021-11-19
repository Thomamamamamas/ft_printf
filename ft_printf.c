/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:17:23 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/19 12:47:25 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <string.h>
#include "Libft/libft.h"

char	*parse_flag(const char *content, size_t *n)
{
	char	*res;

	if (content[n] - 1 == '%' && content[n] == 'd')
	{
		res = ft_itoa();
		
	}
	return (res);
}

int	ft_printf(const char *content, ...)
{
	va_list	arguments;
	void	current_argument;
	char	*str;
	char	*tmp;
	size_t		n;

	va_start(arguments, content);
	while (str[n])
	{
		if (str[n] == '%')
		{
			current_argument = va_arg(arguments, void);
			tmp = parse_flag(content, n, current_argument);  
		}
		n++;
	}
	va_end(arguments);
	return (0);
}
