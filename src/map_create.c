/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:58:08 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/28 16:10:47 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char **create_map(t_ft *f)
{
	char	**map;
	int		i;

	i = 0;
	if(!(f->map = (char **)malloc(sizeof(char *) * (f->size + 1))))
		return (NULL);
	f->map[f->size] = NULL;
	while(i < f->size)
	{
		f->map[i] = (char *)malloc(sizeof(char) * (f->size + 1));
		ft_memset(f->map[i], 46, f->size);
		f->map[i][f->size] = '\0'; 
		i++;
	}
	return (f->map);
}

void free_map(t_ft *f)
{
	int i;

	i = 0;
	while (i < f->size)
		ft_strdel(&f->map[i++]);
	f->size++;
	create_map(f);
}

static int	ft_sqrt(int nb)
{
	int sqrt;

	sqrt = 2;
	while (nb > sqrt * sqrt)
		sqrt++;
	return (sqrt);
}

void	map_size(t_ft *f)
{
	//size = f->maps[f->cmi].x[0] + f->maps[f->cmi].x[1] + f->maps[f->cmi].x[2];
	//size += f->maps[f->cmi].y[0] + f->maps[f->cmi].y[1] + f->maps[f->cmi].y[2];
	//if (size == 4 && f->cmi == 1)
	//	create_map(2);
	//else

//	if (f->size == 0)
		f->size = ft_sqrt(f->cmi * 4);
		create_map(f);
}