/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:57:43 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/19 19:00:10 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*negative_str_to_positive(char *str, t_ptfo *po)
{
	int	tmp;

	tmp = ft_atoi(str) * -1;
	if (str)
		free(str);
	str = ft_itoa(tmp);
	if (tmp > 0)
		po->len += ft_putchar('-');
	return (str);
}
