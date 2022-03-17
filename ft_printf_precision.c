/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 11:23:53 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/17 16:08:02 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

int	apply_justification(char *str, t_ptfo *po)
{
	int	just_len;
	int	n;

	n = 0;
	if (po->zero_filled == 1 && po->l_just == 0)
		return (0);
	else if (po->r_just_value != 0)
		just_len = po->r_just_value - ft_strlen(str);
	else
		just_len = po->l_just_value - ft_strlen(str);
	if (po->conversion == 'c')
		just_len--;
	else if (po->conversion == 'p' || po->sharp == 1)
		just_len = just_len - 2;
	if ((po->i_sign == 1 || po->p_sign == 1) && ft_atoi(str) >= 0)
		just_len--;
	if (just_len > 0)
	{
		while (n++ < just_len)
			ft_putchar(' ');
	}
	if (n <= 0)
		return (n);
	return (n - 1);
}

int	apply_p_sign(char *str, t_ptfo *po)
{
	if (po->p_sign == 1 && conversion_is_number(po->conversion))
	{
		if (ft_atoi(str) >= 0)
			return (ft_putchar('+'));
	}
	return (0);
}

int	apply_i_sign(char *str, t_ptfo *po)
{
	if (po->i_sign == 1 && conversion_is_number(po->conversion))
	{
		if (po->p_sign == 0  && ft_atoi(str) >= 0)
			return (ft_putchar(' '));
	}
	return (0);
}

int	apply_sharp(t_ptfo *po)
{
	if (po->conversion == 'x' || po->conversion == 'p')
		return (ft_putstr("0x"));
	else if (po->conversion == 'X')
		return (ft_putstr("0X"));
	return (0);
}

int	fill_with_zero(char *str, t_ptfo *po)
{
	int	fill_len;
	int	n;

	n = 0;
	if (po->zero_filled == 1 && po->l_just == 0)
	{
		if (po->r_just_value != 0)
			fill_len = po->r_just_value - ft_strlen(str);
		else 
			fill_len = po->l_just_value - ft_strlen(str);
		if (po->i_sign == 1 || po->p_sign == 1)
			fill_len--;
		while (n++ < fill_len)
			ft_putchar('0');
	}
	if (n <= 0)
		return (n);
	return (n - 1);
}
