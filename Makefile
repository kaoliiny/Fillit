# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 19:52:44 by kaoliiny          #+#    #+#              #
#    Updated: 2019/01/07 14:13:13 by kaoliiny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		all clean fclean re mclean mfclean mre

NAME :=		fillit

SRC_PATH :=	src/
INC_PATH :=	includes/
LIB_PATH :=	libft/
OBJ_PATH :=	.obj/

CC :=		clang
CFLAGS :=	-Wall -Werror -Wextra
IFLAGS :=	-I $(INC_PATH)

HFILES :=	fillit
FILES :=	main map_create backtracking scriber ft_putendl ft_putendl_fd  \
				ft_strlen ft_bzero ft_memset get_next_line ft_strequ \
				ft_strdup ft_lstnew ft_strjoin ft_memcpy ft_lstadd ft_strsub \
				ft_strnew ft_strcpy ft_strcat ft_strchr ft_strdel  

HDRS :=		$(addprefix $(INC_PATH), $(addsuffix .h, $(HFILES)))
SRCS :=		$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS :=		$(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) -o $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)$(SRC_PATH)
$(OBJ_PATH)%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean: mclean
	make clean -C
fclean: mfclean
	make fclean -C
re: fclean all

mclean:
	rm -f $(OBJS)
mfclean:
	rm -f $(NAME)
	rm -rf $(OBJ_PATH)
mre: mfclean all
