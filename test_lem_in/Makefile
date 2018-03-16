# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atourner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 10:28:24 by atourner          #+#    #+#              #
#    Updated: 2018/03/16 15:12:40 by atourner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES_LIB=includes

all: comp_lem error_comp normal_comp error_test normal_test

comp_lem:
	@printf "Compiling your lem-in\n"
	@make -C ../

error_comp:
	@printf "Compiling everything needed for testing errors\n"
	@gcc test_error.c -I$(INCLUDES_LIB) lib/libftprintf.a -o error

normal_comp:
	@printf "Compiling everything needed for testing normal\n"
	@gcc test_normal.c -I$(INCLUDES_LIB) lib/libftprintf.a -o normal

error_test:
	@printf "Testing error, check error.txt if there is error\n"
	@sh scripts/error.sh

normal_test:
	@echo "\nNormal launch\nif green, optimal is reach\nif orange, optimal isn't reach\nif red, reponse if false\nCheck normal.txt\nIt only check the number of room, not if it is correct ! Check the result yourself!"
	@sh scripts/normal.sh

clean:
	@rm -rf error lem-in normal normal.txt error.txt
	@make fclean -C ../
