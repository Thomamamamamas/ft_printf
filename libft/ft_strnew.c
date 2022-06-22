/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:02:40 by tcasale           #+#    #+#             */
/*   Updated: 2022/06/22 17:02:52 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (i < size + 1)
	{
		*((char *)str + i) = (int) '\0';
		i++;
	}
	return (str);
}
/*
int	main()
{
	size_t	size = 5;
	ft_strnew(size);
	return (0);
}
*/
