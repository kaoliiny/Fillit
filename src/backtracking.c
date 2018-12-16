/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiyn <kaoliiyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:14:08 by vbrazas           #+#    #+#             */
/*   Updated: 2018/12/16 04:57:40 by kaoliiyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print(t_ft *f)
{
	int i;

	i = -1;
	while (++i < f->size)
		ft_putendl(f->map[i]);
}

void	ft_clean(t_ft *f, int fig)
{
	int i;
	int j;

	i = -1;
	while (++i < f->size && (j = -1))
		while (++j < f->size)
			if (f->map[i][j] == f->maps[fig].letter)
				f->map[i][j] = '.';
}

char	**ft_try(t_ft *f, int x, int y, int fig)
{
	int i;
	int	counter;

	i = 0;
	counter = 0;
	if (y < f->size && f->map[y][x] == '.')
		counter++;
	else
		return (NULL);
	while (i < 3 && MAP_Y(fig, i) + y < f->size)
	{
		if (f->map[MAP_Y(fig, i) + y][MAP_X(fig, i) + x] == '.')
			counter++;
		i++;
	}
	if (counter == 4)
	{
		f->map[y][x] = f->maps[fig].letter;
		while (--i >= 0 && MAP_Y(fig, i) + y < f->size)
			f->map[MAP_Y(fig, i) + y][MAP_X(fig, i) + x] = f->maps[fig].letter;
		return (f->map);
	}
	return (NULL);
}

void	norm_onelove(t_ft *f, int fig)
{
	CX(fig) = 0;
	CY(fig) = 0;
	CX(--fig)++;
	ft_clean(f, fig);
	if (f->cmi != 1)
		(fig == -1) ?
		free_map(f, 1, &fig) : ft_backtracking(f, fig);
}

char	**ft_backtracking(t_ft *f, int fig)
{
	if (++f->cnti >= 95000)
	{
		free_map(f, 1, &f->cnti);
		return (NULL);
	}
	while (MAP_Y(fig, 2) >= f->size || MAP_X(fig, 2) >= f->size)
		free_map(f, 0, &fig);
	while (fig < f->cmi)
	{
		(CX(fig) == f->size) ? (++CY(fig) && (CX(fig) = 0)) : 0;
		if (ft_try(f, CX(fig), CY(fig), fig) == NULL)
		{
			CX(fig)++;
			if (CX(fig) == f->size && CY(fig) >= f->size - 1 - MAP_Y(fig, 2))
			{
				norm_onelove(f, fig);
				return (NULL);
			}
		}
		else
			return (ft_backtracking(f, ++fig));
	}
	ft_print(f);
	return (f->map);
}
