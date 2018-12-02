/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:59:36 by ytrubach          #+#    #+#             */
/*   Updated: 2018/12/02 20:45:02 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <libft.h>

//# define BUFF_SIZE 5
#define MAP_X(fig, i)	(f->maps[fig].x[i])
#define MAP_Y(fig, i)	(f->maps[fig].y[i])

#define CX(fig)			(f->maps[fig].cx)
#define CY(fig)			(f->maps[fig].cy)

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
	t_coord		maps[27];
	int			cmi;
	char		**map;
	int			size;

}					t_ft;

void	ft_error(int errnum);

void	map_size(t_ft *f);
//char				**fillit(char **str, int fd);
char	**ft_backtracking(t_ft *f, int fig);

void free_map(t_ft *f);
//int     			check_neib(char **arr);

#endif