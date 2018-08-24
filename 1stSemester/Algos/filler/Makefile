# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 07:13:32 by lde-jage          #+#    #+#              #
#    Updated: 2017/07/08 11:35:23 by lde-jage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lde-jage.filler

HDR = includes/*.h\
	  libft/libft.h

SRC = srcs/*.c

LIBFT = -L libft/ -lft

OPT = *.o

FLAGS = -Wall -Wextra -Werror -iquoteincludes -iquotelibft -g

$(NAME): all

all:
	make -C libft/ fclean && make -C libft/
	gcc -c $(HDR) $(SRC) $(FLAGS)
	gcc -o $(NAME) $(OPT) $(LIBFT) $(FLAGS)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
