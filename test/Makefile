# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atourner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 10:28:24 by atourner          #+#    #+#              #
#    Updated: 2018/03/07 10:30:53 by atourner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES_LIB=includes

all: cpy_lem error_comp error_test

cpy_lem:
	cp ../lem-in .

error_comp:
	gcc test_error.c -I$(INCLUDES_LIB) libftprintf.a -o error

error_test:
	sh error.sh

clean:
	rm -rf error lem-in
