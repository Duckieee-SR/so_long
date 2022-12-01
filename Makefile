# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 16:26:20 by ralves-g          #+#    #+#              #
#    Updated: 2022/12/01 18:49:13 by gamaro-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror #-fsanitize=address -g
MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit
MLX_LINUX	=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM			=	rm -f

NAME		=	so_long
NAME2		=	so_long_linux

INCLUDE		=	-I ./
SRCS_		=	so_long.c \
				map_utils.c \
				get_next_line.c \
				get_next_line_utils.c\
				map_utils2.c \
				map_utils3.c \
				map_utils4.c \
				map_utils5.c \
				Print_map_extra.c

SRCS		=	$(addprefix $(_SRC), $(SRCS_))

_OBJ		=	./obj/
_SRC		= 	./src/
OBJS		=	$(patsubst $(_SRC)%.c, $(_OBJ)%.o, $(SRCS))


all:		$(NAME)
	
$(_OBJ)%.o: $(_SRC)%.c
	$(CC) -c $< -o $@

# $(NAME): $(_OBJ) $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME) $(INCLUDE)

# linux:		$(NAME2)

$(NAME): $(_OBJ) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LINUX) -o $(NAME) $(INCLUDE)
	
#bonus:		$(SRCS_B) $(OBJS_B)
#			$(CC) $(CFLAGS) $(SRCS_B) -o $(NAME_B)
#			$(CC) $(CFLAGS) $(SRCS_B) -c

$(_OBJ):
	mkdir $@

clean:
	$(RM) -r $(_OBJ)

fclean:	clean
	$(RM) $(NAME) $(NAME2)

re:	fclean all
