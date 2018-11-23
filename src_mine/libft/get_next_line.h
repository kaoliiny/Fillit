/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:29:19 by ytrubach          #+#    #+#             */
/*   Updated: 2018/11/22 20:55:40 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"

# define BUFF_SIZE 100

typedef struct			s_filelist
{
	int					fd;
	char				*pointline;
	struct s_filelist	*next;
}						t_fileelist;

int						get_next_line(const int fd, char **line);

#endif
