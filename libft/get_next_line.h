/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrubach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:29:19 by ytrubach          #+#    #+#             */
/*   Updated: 2018/11/16 15:49:23 by ytrubach         ###   ########.fr       */
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
# include "libft/libft.h"

# define BUFF_SIZE 100

typedef struct			s_filelist
{
	int					fd;
	char				*pointline;
	struct s_filelist	*next;
}						t_filelist;

int						get_next_line(const int fd, char **line);

#endif
