/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:59:36 by ytrubach          #+#    #+#             */
/*   Updated: 2018/11/22 22:29:21 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdio.h> //
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

//# define BUFF_SIZE 5

typedef struct		s_coord
{
	int				x[3];
	int				y[3];
	char			letter;

}					t_coord;

t_coord		a[26];
t_coord		*c;

int					get_next_line(const int fd, char **line);

//char				**fillit(char **str, int fd);

//int     			check_neib(char **arr);

#endif