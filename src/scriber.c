/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scriber.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:16:43 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/12/08 22:04:10 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		rec_coord(int xy[], int i, int j, t_ft *f)
{
	++f->enter;
	f->maps[f->cmi].letter = 'A' + f->cmi;
	f->maps[f->cmi].x[f->enter - 1] = j - xy[0];
	f->maps[f->cmi].y[f->enter - 1] = i - xy[1];
	if (f->enter == 3)
		f->cmi++;
}

static void		check_con(char *arr[4], int *con, int i, int j)
{
	if (j < 3 && arr[i][j + 1] == '#')
		(*con)++;
	if (i < 3 && arr[i + 1][j] == '#')
		(*con)++;
}

static void		scriber(char *arr[4], t_ft *f)
{
	int		i;
	int		j;
	int		con;
	int		xy[2];

	f->enter = -1;
	con = 0;
	i = -1;
	while (++i < 4 && (j = -1))
	{
		while (++j < 4)
			if (arr[i][j] == '#')
			{
				if (f->enter == -1 && (xy[1] = i) | 1
				&& (xy[0] = j) | 1)
					++f->enter;
				else
					rec_coord(xy, i, j, f);
				check_con(arr, &con, i, j);
			}
			else (arr[i][j] != '.') ? ft_error(7) : 0;
	}
	con != 3 && (con != 4 || (MAP_Y(f->cmi - 1, 2) != 1
	|| MAP_X(f->cmi - 1, 2) != 1)) && ft_error(8);
}

void			check_map(int fd, t_ft *f)
{
	char		*line;
	char		*arr[4];
	int			ret;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while ((ret = get_next_line(fd, &line) > 0) && ++i <= 129)
		if (j == 4)
		{
			(!ft_strequ(line, "")) ? ft_error(3) : 0;
			scriber(arr, f);
			while (j)
				free(arr[--j]);
		}
		else
			(ft_strlen(line) != 4) ? ft_error(2) : (arr[j++] = line);
	(j == 4) ? scriber(arr, f) : ft_error(3);
	(i == 130) ? ft_error(4) : 0;
	(ret < 0) ? ft_error(5) : 0;
}
