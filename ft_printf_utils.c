/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:08:03 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/17 16:04:38 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	init_ptfo(t_ptfo *po)
{
	po->has_flag = 0;
	po->sharp = 0;
	po->zero_filled = 0;
	po->r_just_value = 0;
	po->l_just = 0;
	po->l_just_value = 0;
	po->p_sign = 0;
	po->i_sign = 0;
	po->conversion = 0;
}

void	write_argument(char *str, va_list arguments, t_ptfo *po)
{
	if (po->conversion == 'c')
		po->len += ft_putchar(va_arg(arguments, int));
	else if (po->conversion == 'x')
		po->len += write_lower_x(str);
	else if (po->conversion == '%')
		po->len += ft_putchar('%');
	else
		po->len += ft_putstr(str);
}

int		write_lower_x(char *str)
{
	int	n;
	int	len;

	n = 0;
	len = 0;
	while (str[n])
	{
		if (ft_isalpha(str[n]))
			len += ft_putchar(ft_tolower(str[n]));
		else
			len += ft_putchar(str[n]);
		n++;
	}
	return (len);
}
