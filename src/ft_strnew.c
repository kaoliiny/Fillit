/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 19:37:19 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/01/07 14:24:52 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *tmp;
	char *str;

	str = (char*)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	tmp = str;
	while (size)
	{
		*tmp++ = '\0';
		size--;
	}
	*tmp = '\0';
	return (str);
}
