/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:14:08 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/12/06 23:00:02 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_error(int errnum)
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
}

int			main(int argc, char **argv)
{
	t_ft	f;
	int		fd;

	ft_bzero(&f, sizeof(t_ft));
	(argc != 2) ? ft_error(1) : 0;
	fd = open(argv[1], O_RDONLY);
	((fd) <= 0) ? ft_error(1) : 0;
	check_map(fd, &f);
	map_size(&f);
	ft_backtracking(&f, 0);
	return (0);
}
