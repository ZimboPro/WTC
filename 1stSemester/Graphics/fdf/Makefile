# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/26 11:34:32 by lde-jage          #+#    #+#              #
#    Updated: 2017/06/30 08:30:26 by lde-jage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = srcs/*.c

HDR = 	includes/*.h\
		libft/libft.h

LIBFT = -L libft/ -lft

MLX = minilibx/libmlx.a -framework Opengl -framework Appkit

OPT = *.o

FLAGS = -Wall -Werror -Wextra -iquoteincludes -g

$(NAME): all

all:
	make -C libft/ fclean && make -C libft/
	gcc -c $(HDR) $(SRC) $(FLAGS)
	gcc -o $(NAME) $(OPT) $(LIBFT) $(MLX) $(FLAGS)

clean:
	/bin/rm -f $(OPT)

fclean: clean
	/bin/ rm -f $(NAME)

re: fclean all
