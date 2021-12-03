/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:18:19 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/03 13:07:21 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct	s_printf
{
	char	actual_percent;
	char	last_percent;
}				t_printf;

int				parse_conversion(int conversion, va_list arguments);
int				ft_printf(const char *content, ...);

//Conversion

void			c_conversion(va_list arguments);
char			*s_conversion(va_list arguments);
char			*pxX_conversion(va_list arguments, int conversion);
char			*di_conversion(va_list arguments);
char			*u_conversion(va_list arguments);

#endif
