/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:58:08 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/12/10 20:12:28 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**create_map(t_ft *f)
{
	int		i;

	i = 0;
	if (!(f->map = (char **)malloc(sizeof(char *) * (f->size + 1))))
		return (NULL);
	f->map[f->size] = NULL;
	while (i < f->size)
	{
		f->map[i] = (char *)malloc(sizeof(char) * (f->size + 1));
		ft_memset(f->map[i], 46, f->size);
		f->map[i][f->size] = '\0';
		i++;
	}
	return (f->map);
}

void			free_map(t_ft *f, int d, int *fig)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	*fig = 0;
	while (j < f->cmi)
	{
		CX(j) = 0;
		CY(j) = 0;
		j++;
	}
	while (i < f->size)
		free(f->map[i++]);
	free(f->map);
	f->size++;
	create_map(f);
	(d == 1) ? ft_backtracking(f, 0) : 0;
	(d == 2) ? CX(--j)++ && ft_backtracking(f, 0) : 0;
}

static int		ft_sqrt(int nb)
{
	int		sqrt;

	sqrt = 2;
	while (nb > sqrt * sqrt)
		sqrt++;
	return (sqrt);
}

void			map_size(t_ft *f)
{
	f->size = ft_sqrt(f->cmi * 4);
	create_map(f);
}
