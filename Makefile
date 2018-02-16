# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atourner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/21 01:31:15 by atourner          #+#    #+#              #
#    Updated: 2018/02/16 10:57:15 by atourner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LEM = lem-in

FLAGS = -Wall -Werror -Wextra

LIB = ft_printf/libftprintf.a

INCLUDES_LIB = ft_printf/includes

INCLUDES_LEM = ft_lem-in/includes

SRC_LEM = ft_lem-in/lem-in.c

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
	@rm -rf $(COMP_LEM)

re : fclean all
