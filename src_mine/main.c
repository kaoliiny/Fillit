/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:16:43 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/23 22:30:18 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_recover(char *line, int num, int figure, t_coord *c)
{
	int			i;
	static int	j;
	static int	coord[2];

	i = 0;
	while (i < 4)
	{
		if ((line[i] == '#' && coord[0] == 0 && coord[1] == 0) || (j == -1))
		{
			coord[0] = i;
			coord[1] = (num % 5) - 1;
			j = 0;
		}
		else if ((line[i] == '#' && i + (num % 5 - 1) - coord[0] - coord[1] == 1) ||
		(line[i] == '#' && i + (num % 5 - 1) - c[figure - 1].x[j - 1] - coord[0] - coord[1] - c[figure - 1].y[j - 1] == 1))
		{
			c[figure - 1].x[j] = i - coord[0];
			c[figure - 1].y[j] = num % 5 - 1 - coord[1];
			printf("%d|	%d|	%d\n", j, c[figure - 1].x[j], c[figure - 1].y[j]);
			++j % 3 ? j : (j = -1);
		}
	//	else if (line[i] == '#')
	//	printf("%d---", figure);
		i++;
	}
	return (1);
}

static int		check_map(int fd, t_coord *a)
{
	char		*line;
	int			cnt_map;
	int			cnt_symb;
	int			i;
	int			j;

	j = 0;
	i = 1;
	cnt_map = 1;
	line = NULL;
	while (get_next_line(fd, &line) && i < 129)
	{
        if (!(i % 5))
        {
             if (ft_strlen(line) == 0)
             {
                cnt_map++;
                cnt_symb = 0;
             }
             else 
                 return (0);
        }
        else 
        {
            if (ft_strlen(line) != 4)
             return (0);
            j = 0;
            while (line[j])
            {
                if (line[j] != '.' && line[j] != '#')
                    return (0);
                if(line[j] == '#')
                    cnt_symb++;
                j++;
            }
			ft_recover(line, i, cnt_map, a);
		}
	//  printf("%d%s\n", i, line);
		i++;
	}
	return(1);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_coord		a[26];

	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || (fd) <= 0)
	{
		write(1, "Error", 6);
		return (1);
	}
	if ((fd = check_map(fd, a)))
		printf("Here we're!%d\n", fd);
	return (0);
}
