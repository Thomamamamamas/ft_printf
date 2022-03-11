/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:18:19 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/11 20:09:17 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

int				ft_printf(const char *content, ...);

//ft_printf_utils

int				parse_conversion(int conversion, va_list arguments);
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_putnbr(int n);
int				ft_putnbr_unsigned(int n);

//ft_printf_utils_2

int				ft_put_address(unsigned long long n);
int				ft_putnbr_hexa(long long n);
int				ft_putnbr_hexa_lower(long long n);
int				ft_putaddress(unsigned long long n);

#endif
