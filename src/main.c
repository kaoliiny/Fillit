/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiyn <kaoliiyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:14:08 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/12/16 05:40:54 by kaoliiyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_error(int errnum)
{
	const char	*errmessages[20] = {"",
	"1. There must be exactly one valid file. Please follow the rules",
	"2. Figure's map must be only 4x4 symbols in input and have one \\n",
	"3. Invalid input",
	"4. OH no! There is too many tetrininos around!",
	"5. must be one '\\n' in the end of file!",
	"6. In one figure must be four and only four lines",
	"7. Invalid symbol in the map!",
	"8. In one figure's line must be only four characters '#'!"};

	ft_putendl_fd(errmessages[errnum], 2);
	exit(errnum);
	return (1);
}

static int	ft_valid_newline(const char *fn)
{
	int		fd;
	char	buff[700];
	int		ret;

	fd = open(fn, O_RDONLY);
	while ((ret = read(fd, buff, 700)) > 0)
		buff[ret] = '\0';
	close(fd);
	if (buff[ft_strlen(buff) - 1] != '\n')
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	t_ft	f;
	int		fd;

	ft_bzero(&f, sizeof(t_ft));
	(argc != 2) ? ft_error(1) : 0;
	fd = open(argv[1], O_RDONLY);
	((fd) <= 0) ? ft_error(1) : 0;
	(ft_valid_newline(argv[1])) ? check_map(fd, &f) : ft_error(1);
	map_size(&f);
	ft_backtracking(&f, 0);
	return (0);
}
