# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vifonne <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:05:19 by vifonne           #+#    #+#              #
#    Updated: 2018/11/23 15:32:09 by vifonne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		main.c					\
					parsing.c				\
					ft_error.c				\
					ft_error_str.c			\
					ft_error_tab.c			\
					ft_error_struct.c		\
					ft_error_struct_str.c	\
					ft_init.c				\
					ft_set_stock_to_zero.c	\
					ft_resolve.c			\
					ft_print_square.c		\
					ft_check.c				\
					ft_manage_sq.c			\
					ft_dim.c				\

INCLUDES	=		includes/

OBJ			=		$(SRCS:.c=.o)

CC			=		gcc -Wall -Wextra -Werror

NAME		=		fillit

_RED=$'\x1b[31m$'
_GREEN=$'\x1b[32m$'
_YELLOW=$'\x1b[33m$'
_BLUE=$'\x1b[34m$'
_CYAN=$'\x1b[36m$'
_WHITE=$'\x1b[37m$'

all:	$(NAME)

$(NAME): $(OBJ) $(SRCS)
	@echo "$(_CYAN)"
	make -C libft/
	@echo "$(_YELLOW)"
	$(CC) $(SRCS) -o $(NAME) -I libft/includes -I $(INCLUDES) -L libft/ -lft

clean:
	@echo "$(_RED)"
	rm -f $(OBJ)
	make clean -C ./libft/

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./libft/

re:	fclean $(NAME)
