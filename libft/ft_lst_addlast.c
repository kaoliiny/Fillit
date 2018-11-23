/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 22:54:56 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/11 18:39:40 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_addlast(t_list **begin_list, void *data)
{
	t_list *el;

	el = *begin_list;
	if (el && **begin_list)
	{
		while (el->next)
			el = el->next;
		el->next = ft_lstnew(content);
	}
	else
		*el = ft_lstnew(content);
}
