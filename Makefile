# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 02:44:37 by abel-hid          #+#    #+#              #
#    Updated: 2023/12/11 21:48:29 by abel-hid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

SRCS =	main.c\
		get_next_line.c\
		get_next_line_utils.c\
		split.c\
		parsing_cub.c\
		parssing.c\
		floor.c\
		init_map.c\
		empty.c\
		texture.c\
		map.c\
		free_map.c\
		player.c\
		update_map.c\
		wall.c\
		moves.c\
		hook.c\

OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(OBJS) MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"  -o $(NAME) 
%.o: %.c cub3D.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all