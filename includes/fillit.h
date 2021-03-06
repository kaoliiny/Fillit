/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:59:36 by ytrubach          #+#    #+#             */
/*   Updated: 2019/01/07 13:32:01 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define ABS(Value) ((Value) < 0 ? -(Value) : (Value))

# define MAP_X(fig, i)	(f->maps[fig].x[i])
# define MAP_Y(fig, i)	(f->maps[fig].y[i])

# define CX(fig)		(f->maps[fig].cx)
# define CY(fig)		(f->maps[fig].cy)

typedef struct		s_coord
{
	char			letter;
	int				x[3];
	int				y[3];
	int				cx;
	int				cy;

}					t_coord;

typedef struct		s_fillit
{
	t_coord			maps[27];
	int				cmi;
	int				cnti;
	int				enter;
	char			**map;
	int				size;

}					t_ft;

int					ft_error(int errnum);

void				map_size(t_ft *f);

void				check_map(int fd, t_ft *f);

char				**ft_backtracking(t_ft *f, int fig);

void				free_map(t_ft *f, int d, int *fig);

#endif
