/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:20:04 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/18 09:16:03 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>


void	handle_percent(const char *content, va_list arguments, t_ptfo *po)
{
	char	*str;

	parse_conversion(content, po);
	parse_flag(content, po);
	str = do_conversion(arguments, po);
	if (po->r_just_value != 0)
		po->len += apply_justification(str, po);
	po->len += apply_p_sign(str, po);
	po->len += apply_i_sign(str, po);
	po->len += fill_with_zero(str, po);
	if (po->sharp == 1 || po->conversion == 'p')
		po->len += apply_sharp(str, po);
	write_argument(str, arguments, po);
	if (po->l_just == 1)
		po->len += apply_justification(str, po);
	free(str);
}

void	parse_flag(const char *content, t_ptfo *po)
{
	int	just_value;

	just_value = 0;
	content++;
	while (*content)
	{
		if (*content == '-')
		{
			if (just_value != 0)
				po->l_just_value = just_value;
			po->l_just = 1;
		}
		else if (*content == '+')
			po->p_sign = 1;
		else if (ft_isdigit(*content))
		{
			if (*content == '0' && just_value == 0)
				po->zero_filled = 1;
			else
			{
				just_value = just_value * 10 + *content - 48;
				if (po->l_just == 1)
					po->l_just_value = just_value;
			}
		}
		else if (*content == ' ')
			po->i_sign = 1;
		else if (*content == '#')
			po->sharp = 1;
		else
		{
			if (po->l_just == 0 && just_value > 0)
				po->r_just_value = just_value;
			return ;
		}
		content++;
		po->has_flag = 1;
	}
}

void		parse_conversion(const char *content, t_ptfo *po)
{
	int	first;

	first = 0;
	while (*content && (!ft_isalpha(*content) && po->conversion == 0))
	{
		if (*content == '%' && first == 0)
			first++;
		else if (*content == '%' && first == 1)
			po->conversion = *content;
		content++;
	}
	if (ft_isalpha(*content) || *content == '%')
		po->conversion = *content;
}
