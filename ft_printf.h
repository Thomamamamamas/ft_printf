/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:18:19 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/20 15:39:08 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "Libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_printf
{
	char	actual_percent;
	char	last_percent;
}				t_printf;

void			parse_conversion(int conversion, va_list arguments);
int				ft_printf(const char *content, ...);

#endif
