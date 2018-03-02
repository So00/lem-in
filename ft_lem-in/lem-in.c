/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 10:49:58 by atourner          #+#    #+#             */
/*   Updated: 2018/03/02 13:28:32 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"

int		main()
{
	t_room		*anthill;

	anthill = ft_get_anthill();
	if (!anthill)
		ft_printf("ERROR\n");
	if (anthill)
		free_all_room(anthill);
return (0);
}
