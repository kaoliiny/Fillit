/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrubach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:28:50 by ytrubach          #+#    #+#             */
/*   Updated: 2018/11/04 17:28:53 by ytrubach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			readline(t_list **noda, char ***line)
{
	int		len;
	char	*leak;

	len = 0;
	leak = (*noda)->content;
	if (ft_strlen(leak) == 0)
		return (0);
	while (leak[len] != '\n' && leak[len])
		len++;
	**line = ft_strsub(leak, 0, len);
	if (leak[len] != '\n')
		(*noda)->content = ft_strdup(ft_strchr(leak, '\0'));
	else
		(*noda)->content = ft_strdup(ft_strchr(leak, '\n') + 1);
	free(leak);
	return (1);
}

t_list		*searchlist(t_list **list, size_t fd)
{
	t_list *tmp;
	t_list *new;

	tmp = (*list);
	if ((*list) == 0)
	{
		(*list) = ft_lstnew("", fd);
		return ((*list));
	}
	while (tmp != 0)
	{
		if (tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	new = ft_lstnew("", fd);
	ft_lstadd(list, new);
	return (new);
}

void		read_f(t_list **pnt, int fd)
{
	int		ret;
	char	*str;
	char	*buff;

	buff = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		str = (*pnt)->content;
		(*pnt)->content = ft_strjoin((*pnt)->content, buff);
		free(str);
		if (ft_strchr((*pnt)->content, '\n'))
			break ;
	}
	free(buff);
}

int			get_next_line(const int fd, char **line)
{
	static t_list		*files;
	char				*leak;
	t_list				*pnt;

	if (!(leak = (char*)malloc(sizeof(char))))
		return (-1);
	if (fd < 0 || read(fd, leak, 0) < 0)
		return (-1);
	free(leak);
	pnt = searchlist(&files, fd);
	read_f(&pnt, fd);
	return (readline(&pnt, &line));
}
