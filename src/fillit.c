/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrubach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:59:50 by ytrubach          #+#    #+#             */
/*   Updated: 2018/11/20 13:59:54 by ytrubach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// int validsize(char *s)
// {
// 	int width;
// 	int height;

// 	while ()
// 	{

// 	}
// 	return 0;
// }

char **read_file(int fd)
{
	// char	*line;
	char 	**arr;
	// int 	fd; 
	int 	i;
	// int		j;
	// int		flag_valid;

	// i = 0;
	// j = 0;
	// fd = open(f_name, O_RDONLY);
	// arr = (char **)malloc(sizeof(char*) * 4 + 1);
	
	int		ret;
	char	*str;
	char	*buff;

int h = 0;
int v = 0;
int w = 0;
	//arr = (char*)malloc(sizeof() * 26);
	buff = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		i = 0;
		buff[ret] = '\0';
		while (i < 4)
		{
			if (buff[0] == '#' || buff[0] == '.')
				str = ft_strjoin(str, buff);
			//free(str);
			else
				return (0);
			i++;
		}
		if (i == 5 && (buff[0] == '\n'))
		{
			arr[h][v][w] = str[w];
			w++;
			i = 0;
		}
		v++;
	}
	free(buff);
	return (arr);
	
}

int fillit(char *f_name)
{
// char	*line;
// 	char 	**arr;
// 	int 	fd; 
// 	int 	i;
// 	int j;
// 	//int len = 0;
// 	int flag_valid;

	i = 0;
	j = 0;
	fd = open(f_name, O_RDONLY);

	char 	***arr;
	arr = read_file(fd);
	if (!arr)
		return 0;
	while (i < 2 && j < 4)
	{
		printf("%s", arr[0][j]);
		j++;
	}
	return 1;
	//while (i < 4)
	//{

		//flag_valid = validation(line);
		// if (flag_valid)
		// {
		// 	arr[j] = (char *)malloc(sizeof(char) * 4 + 1);
		// 	free(line);
		// 	line = NULL;
		// }
		//len = ft_strlen(line);
		//

		//arr[j] = *line;
	//	printf("\n ***** line1 in fd1 [%s] \n", arr[j]);
		
	//	i++;
		//j++;
	//}
	
	// if (!(validation(line)))
	// {
	// 	// вызов функции работы с полученной строкой
	// 	free(line);
	// 	return NULL;
	// }
	
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error", 6);
		return (1);
	}
	fillit(argv[1]);
	return (0);
}