/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 00:58:03 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/01/07 14:23:37 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	char	*x;
	int		i;

	i = ft_strlen((char*)str);
	x = (char *)malloc(sizeof(*x) * (i + 1));
	if (x == 0)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		x[i] = str[i];
		i++;
	}
	x[i] = '\0';
	return (x);
}