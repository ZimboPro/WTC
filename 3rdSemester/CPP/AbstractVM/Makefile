# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/21 08:10:36 by lde-jage          #+#    #+#              #
#    Updated: 2018/06/21 08:10:43 by lde-jage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm

CC = clang++

MAIN = main.cpp

SRC =	Factory.cpp	\
		Parse.cpp	\
		Logic.cpp

TEST = test/test.cpp

CFLAGS = -Wall -Werror -Wextra -std=c++11

MAIN_OBJ = $(MAIN:.cpp=.o)

OBJS = $(SRC:.cpp=.o)

TEST_OBJ = $(TEST:.cpp=.o)

NEWTEST:= $(subst test/,,$(TEST_OBJ))

LIB_TEST = -I test/gtest/

$(NAME): all

all: ${MAIN_OBJ} ${OBJS}
	${CC} ${CFLAGS} ${INCLUDES} -o $(NAME) ${MAIN_OBJ} ${OBJS} ${LIBS}

clean:
	rm -f *.o

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

fclean: clean
	rm -f $(NAME)
	rm -f unittest

re: fclean all

test:$(TEST_OBJ) ${OBJS}
	${CC} ${CFLAGS} ${INCLUDES} -o unittest $(NEWTEST) ${OBJS} test/gtest/gtest_main.a

retest: fclean test