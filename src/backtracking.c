/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:14:08 by vbrazas           #+#    #+#             */
/*   Updated: 2018/11/28 17:02:18 by kaoliiny         ###   ########.fr       */
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
	if (f->map[y][x] == '.')
		f->map[y][x] = f->maps[fig].letter;
	else 
		return(NULL);
	while(i < 3)
	{
		//printf("f->map[%d][%d] | MAP_Y(fig, i) - %d || i - %d || y - %d ||\n", MAP_Y(fig, i) + y, MAP_X(fig, i) + x, MAP_Y(fig, i), fig, i, y);
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

char **ft_backtracking(t_ft *f, int fig)
{
	int x;
	int y;

	x = 0;
	y = 0;

	while (y < f->size - 1 - MAP_Y(fig, 2) && fig <= f->cmi)
	{
		(x == 4) ? ((++y) && (x = 0)) : 0;
		if (ft_try(f, x, y, fig) == NULL)
		{
			x++;
			if (fig == f->cmi - 1 && y == f->size - 2 - MAP_Y(fig, 2)) //should be here is x as well
			{
				// free map and make bigger map 
				free_map(f);
				ft_print(f);
				return(NULL);
			}
		}
				//ft_print(f);
		else
		{
			return(ft_backtracking(f, ++fig));
	//		return(f->map);
		}
	}

	ft_print(f);
	return(f->map);
//	while(i < f->cmi)
//	{
//		if(t_try(f, x, y) != NULL)
	// 		ft_backtracking(f, ++i)
	// 	else
	// 		x++;
	// }
}
