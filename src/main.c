/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:16:43 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/24 02:45:15 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

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
	// "There must be at least one file",
	// "In one figure's line must be only four characters!",
	// "In one figure must be four and only four lines",
	// "OH no! There is too many tetrininos around!"};

	ft_putendl_fd(errmessages[errnum], 2);
	exit(errnum);
}

static void		scriber(char *arr[4])
{
	int		i;
	int		j;
	int		con;

	con = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (arr[i][j] == '#')
			{
				if ((j < 3 && arr[i][j + 1] == '#')
				|| (i < 3 && arr[i + 1][j] == '#'))
					con++;
				printf("%d", con);
			}
			else if (arr[i][j] != '.')
				ft_error(7);
		}
	}
	(con != 3) ? ft_error(8) : 0;
}

static int		check_map(int fd, t_coord *a)
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
			scriber(arr);
			while (j)
				free(arr[--j]);
		}
		else
			(ft_strlen(line) != 4) ? ft_error(2) : (arr[j++] = line);
	(j == 4) ? scriber(arr) : ft_error(3);
	(i == 129) ? ft_error(4) : 0;
	(ret < 0) ? ft_error(5) : 0;
	return(1);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_coord		a[26];

	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || (fd) <= 0)
		ft_error(1);
	if ((fd = check_map(fd, a)))
		printf("Here we're!%d\n", fd);
	return (0);
}