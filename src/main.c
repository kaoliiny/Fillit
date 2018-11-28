/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:16:43 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/28 16:57:50 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// static int		ft_recover(char *line, int num, int figure, t_coord *c)
// {

// }
// static int		check_map(int fd, t_coord *a)
// {
// 	char		*line;
// 	int			cnt_map;
// 	int			cnt_symb;
// 	int			i;                        
// 	int			j;

// 	j = 0;
// 	i = 1;
// 	cnt_map = 1;
// 	line = NULL;
// 	while (get_next_line(fd, &line) && i < 129)
// 	{
// 		if (!(i % 5))
// 		{
// 			if (ft_strlen(line) == 0)
// 			{
// 				cnt_map++;
// 				cnt_symb = 0;
// 			}
// 			else 
// 				return (0);
// 		}
// 		else 
// 		{
// 			if (ft_strlen(line) != 4)
// 			 return (0);
// 			j = 0;
// 			while (line[j])
// 			{
// 				if (line[j] != '.' && line[j] != '#')
// 					return (0);
// 				if(line[j] == '#')
// 					cnt_symb++;
// 				j++;
// 			}
// 			ft_recover(line, i, cnt_map, a);
// 		}
// 	//  printf("%d%s\n", i, line);
// 		i++;
// 	}
// 	return(1);
// }

void			ft_error(int errnum)
{
	const char	*errmessages[50] = {"",
	"1", "2", "3", "4", "5", "6", "7", "8"};
	// "There must be exactly one file, no more no less",
	// "In one figure's line must be only four characters!",
	// "In one figure must be four and only four lines",
	// "OH no! There is too many tetrininos around!"};

	ft_putendl_fd(errmessages[errnum], 2);
	exit(errnum);
}

static void		rec_coord(int xy[], int i, int j, int enter, t_ft *f)
{
	f->maps[f->cmi].letter = 'A' + f->cmi;
	f->maps[f->cmi].x[enter - 1] = j - xy[0];
	f->maps[f->cmi].y[enter - 1] = i - xy[1];
	if (enter == 3)
		f->cmi++;
}
static void		scriber(char *arr[4], t_ft *f)
{
	int		i;
	int		j;
	int		con;
	int		enter;
	int		xy[2];

	enter = -1;
	con = 0;
	i = -1;
	while (++i < 4 && (j = -1))
	{
		while (++j < 4)
		{
			if (arr[i][j] == '#')
			{
				if (enter == -1)
				{
					xy[0] = j;
					xy[1] = i;
					++enter;
				}
				else
					rec_coord(xy, i, j, ++enter, f);
				if ((j < 3 && arr[i][j + 1] == '#')
				|| (i < 3 && arr[i + 1][j] == '#'))
					con++;
			}
			else if (arr[i][j] != '.')
				ft_error(7);
		}
	}
	(con != 3) ? ft_error(8) : 0;
}

static int		check_map(int fd, t_ft *f)
{
	char		*line;
	char		*arr[4];
	int			ret;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while ((ret = get_next_line(fd, &line) > 0) && ++i < 129)
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
	(i == 129) ? ft_error(4) : 0;
	(ret < 0) ? ft_error(5) : 0;
	return(1);
}

int			main(int argc, char **argv)
{
	t_ft	f;
	int		fd;

	//f.size = 0;
	ft_bzero(&f, sizeof(t_ft));
	(argc != 2) ? ft_error(1) : 0;
	fd = open(argv[1], O_RDONLY);
	((fd) <= 0) ? ft_error(1) : 0;
	check_map(fd, &f);
	map_size(&f);
	printf("Here we're!\n");
	while (ft_backtracking(&f, 0) == NULL)
		;
	return (0);
}
