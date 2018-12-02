/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:14:08 by vbrazas           #+#    #+#             */
/*   Updated: 2018/12/02 20:53:08 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_print(t_ft *f)
{
	int i;

	i = -1;
	while(++i < f->size)
		printf("%s\n", f->map[i]);
	printf("\n");
}

void ft_clean(t_ft *f, int fig)
{
	int i;
	int j;

	i = -1;
	while(++i < f->size  && (j = -1))
		while (++j < f->size)
			if (f->map[i][j] == f->maps[fig].letter)
				f->map[i][j] = '.';
}

char		**ft_try(t_ft *f, int x, int y, int fig)
{
	int i;
	int	counter;

	i = 0;
	counter = 0;
	if (y < f->size && f->map[y][x] == '.')
		f->map[y][x] = f->maps[fig].letter;
	else 
		return(NULL);
	while(i < 3 && MAP_Y(fig, i) + y < f->size)
	{
		if (f->map[MAP_Y(fig, i) + y][MAP_X(fig, i) + x] == '.')
		{
			f->map[MAP_Y(fig, i) + y][MAP_X(fig, i) + x] = f->maps[fig].letter;
			counter++;
		}
	//		ft_print(f);
		i++;
	}
	if (counter != 3)
	{
		ft_clean(f, fig);
		return (NULL);
	}
	return (f->map);
}

//Doesn't work with square

char **ft_backtracking(t_ft *f, int fig)
{
	while (MAP_Y(fig, 2) >= f->size || MAP_X(fig, 2) >= f->size)
	{
		free_map(f);
	}
	while (fig < f->cmi)
	{
		(CX(fig) == f->size) ? (++CY(fig) && (CX(fig) = 0)) : 0;
		if (ft_try(f, CX(fig), CY(fig), fig) == NULL)
		{
			CX(fig)++;
			if (CX(fig) == f->size && CY(fig) >= f->size - 1 - MAP_Y(fig, 2))
			{
				CX(fig) = 0;
				CY(fig) = 0;
				CX(--fig)++;
				ft_clean(f, fig);
			//	return(ft_backtracking(f, fig));
				(fig == -1)	? free_map(f) : 0;
				return(NULL);
			}
		}
		else
			return(ft_backtracking(f, ++fig));
	}
	ft_print(f);
	return(f->map);
}