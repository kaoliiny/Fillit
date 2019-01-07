/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:55:40 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/01/07 14:12:51 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 200

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_bzero(void *s, size_t n);

int				get_next_line(const int fd, char **line);

void			ft_putendl(char const *s);

void			ft_putendl_fd(char const *s, int fd);

int				ft_strequ(char const *s1, char const *s2);

size_t			ft_strlen(const char *str);

int				get_next_line(const int fd, char **line);

void			*ft_memset(void *b, int c, size_t len);

t_list			*ft_lstnew(void const *content, size_t content_size);

char			*ft_strdup(const char *src);

char			*ft_strjoin(char const *str1, char const *str2);

char			*ft_strcpy(char *dest, const char *src);

char			*ft_strcat(char *s1, const char *s2);

char			*ft_strnew(size_t size);

char			*ft_strchr(const char *s, int symbol);

void			ft_strdel(char **ap);

void			*ft_memcpy(void *dst, const void *src, size_t n);

void			ft_lstadd(t_list **alst, t_list *new);

char			*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
