# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prussell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/25 09:58:48 by prussell          #+#    #+#              #
#    Updated: 2017/09/30 20:33:43 by rheukelm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECTS = lib asmc vmc

NONE = \x1b[0m
OK = \x1b[32;01m
WARN = \x1b[33;01m

all: $(PROJECTS)

lib:
	@make -C libft/
	@make -C libft/ clean

asmc:
	@make -C asm/

vmc:
	@make -C vm/

clean:
	@echo "$(WARN)---------- Clean ASM & VM  ----------$(NONE)"
	@make -C vm/ clean
	@make -C asm/ clean

fclean:
	@echo "$(WARN)----------    FClean All    ----------$(NONE)"
	@echo "$(WARN)----------   FClean Libft   ----------$(NONE)"
	@make -C libft/ fclean
	@echo "Removed Libft"
	@echo "$(WARN)----------     Success     ----------$(NONE)\n"
	@make -C vm/ fclean
	@make -C asm/ fclean

re: fclean all
