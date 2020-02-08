# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpace <bpace@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 16:54:31 by bpace             #+#    #+#              #
#    Updated: 2019/09/26 02:40:01 by bpace            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCC = checkerfiles/srcs/* \

SRCP = push_swapfiles/srcs/* \

NAME = push_swap

all: $(NAME)

$(NAME):
	@make -C libft re
	@gcc -Wall -Werror -Wextra $(SRCC) libft/libft.a -o checker
	@gcc -Wall -Werror -Wextra $(SRCP) checkerfiles/srcs/printstack.c checkerfiles/srcs/checkbegin.c checkerfiles/srcs/makefreestack.c checkerfiles/srcs/parser.c checkerfiles/srcs/sp.c libft/libft.a -o push_swap

clean:
		@make -C libft clean

fclean:
		@make -C libft fclean
		@/bin/rm -f $(NAME) checker

re: fclean all
