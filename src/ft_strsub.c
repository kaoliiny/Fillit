/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 14:08:09 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/01/07 14:27:37 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*fresh;
	unsigned int	lens;
	unsigned int	j;

	if (!s)
		return (NULL);
	i = 0;
	lens = ft_strlen((char*)s);
	fresh = (char*)malloc(sizeof(char) * (len + 1));
	if (!fresh || start > lens || start + len > lens)
		return (NULL);
	while (s[i] != '\0' && i != start)
		i++;
	j = 0;
	while (j < len)
	{
		fresh[j] = s[i];
		i++;
		j++;
	}
	fresh[j] = '\0';
	return (fresh);
}
