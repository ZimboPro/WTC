# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/10 07:16:05 by lde-jage          #+#    #+#              #
#    Updated: 2017/07/10 08:00:04 by lde-jage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

HDR = includes/*.h\
	  libft/libft.h

SRC = srcs/*.c

OUT = *.o

FLAGS = -Wall -Wextra -Werror -iquoteincludes -iquotelibft -g

SDL = -lSDL2

LIB = -L libft/ -lft -lm

$(NAME): all

all:
	make -C libft/ fclean && make -C libft/
	gcc -c $(HDR) $(SRC) $(FLAGS)
	gcc -o $(NAME) $(OUT) $(SDL) $(LIB) $(FLAGS)

clean:
	/bin/rm -f $(OUT)
	/bin/rm -f *.gch

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
