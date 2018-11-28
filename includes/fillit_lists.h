/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:59:36 by ytrubach          #+#    #+#             */
/*   Updated: 2018/11/20 18:18:09 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
//# include <sys/types.h>
//# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h> //!
# include <string.h>
# include "libft/libft.h"

# define BUFF_SIZE 1

typedef struct		s_coord
{
	int					x;
	int					y;
	char 				symb;
	struct s_coord		*next;
	struct s_coord		*prev;
}					t_coord;

int					get_next_line(const int fd, char **line);

char				**fillit(char **str, int fd);

#endif