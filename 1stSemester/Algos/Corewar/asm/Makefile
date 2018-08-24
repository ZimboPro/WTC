# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prussell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/25 09:58:48 by prussell          #+#    #+#              #
#    Updated: 2017/09/29 10:21:56 by rheukelm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRCS = srcs/check.c srcs/check2.c srcs/error_checker.c srcs/file_size.c \
	srcs/get_acb.c srcs/get_bytes.c srcs/header.c srcs/line_handling.c \
	srcs/main.c srcs/op.c srcs/print_error.c srcs/read.c srcs/write.c \
	srcs/write2.c srcs/write_functions.c

FLAGS = -Wall -Werror -Wextra -iquoteincludes

NONE = \x1b[0m
OK = \x1b[32;01m
WARN = \x1b[33;01m

all: $(NAME)

$(NAME):
	@echo "$(OK)----------   Compile ASM   ----------$(NONE)"
	@gcc -o $(NAME) $(SRCS) ../libft/libft.a -iquoteincludes $(FLAGS)
	@echo "$(OK)----------     Success     ----------$(NONE)\n"
	
clean:
	@echo "$(WARN)----------    Clean ASM    ----------$(NONE)"
	@rm -f $(NAME)
	@echo "removed $(NAME)"
	@echo "$(WARN)----------     Success     ----------$(NONE)\n"

fclean:
	@echo "$(WARN)----------   FClean ASM    ----------$(NONE)"
	@rm -f $(NAME)
	@echo "removed $(NAME)"
	@echo "$(WARN)----------     Success     ----------$(NONE)\n"

re: fclean all
