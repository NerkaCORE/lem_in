# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 13:23:32 by unli-yaw          #+#    #+#              #
#    Updated: 2017/06/07 16:58:59 by unli-yaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAG = -Wall -Wextra -Werror

NAME = lem-in

LIBDIR = ./libft

SRC = ./srcs/main.c		    \
      ./srcs/get_rooms.c	\
      ./srcs/check_errors.c \
      ./srcs/solve.c        \
      ./srcs/tool.c         \
      ./srcs/move_ants.c    \
      ./srcs/print_moves.c  \
      ./srcs/bonus.c        \
      ./srcs/init_new.c     \

$(NAME):
	@make -C ./libft/
	@$(CC) $(CFLAG) $(SRC) ./libft/libft.a -o $(NAME)
	@echo "\x1b[35m" [~Lem_in generated~] "\x1b[0m"

all: $(NAME)

clean:
	@make -C ./libft clean
	@rm -f $(OBJ)
	@echo "\x1b[32m" [~Folders cleaned~] "\x1b[0m"

fclean:	clean
	@make -C ./libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY : test all re clean fclean
