# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atourner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/16 18:00:36 by atourner          #+#    #+#              #
#    Updated: 2018/02/27 14:04:45 by atourner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LEM = lem-in

LIB = ft_printf/libftprintf.a

INCLUDES_LIB = ft_printf/includes

FLAGS = -Wall -Werror -Wextra

INCLUDES_LEM = ft_lem-in/includes

SRC_LEM = ft_lem-in/lem-in.c\
		  ft_lem-in/ft_get_anthill.c\
		  ft_lem-in/mem_struct_room.c\
		  ft_lem-in/parser2.c\

COMP_LEM = $(SRC_LEM:.c=.o)

all : LIB $(NAME_LEM)

%.o:%.c
	@gcc $(FLAGS) -o $@ -c $< -I$(INCLUDES_LIB) -I$(INCLUDES_LEM)

LIB :
	@make -C ft_printf

$(NAME_LEM) : $(COMP_LEM)
	@echo "\033[0;35mCompilation lem-in\033[0m"
	@gcc $(FLAGS) $(COMP_LEM) $(LIB) -o $(NAME_LEM)

clean :
	@make clean -C ft_printf
	@rm -rf $(COMP_LEM)

fclean : clean
	@make fclean -C ft_printf
	@rm -rf $(NAME_LEM)

re : fclean all
