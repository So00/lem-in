/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 10:49:58 by atourner          #+#    #+#             */
/*   Updated: 2018/03/08 15:42:25 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"

int		main()
{
	t_room		*anthill;
	t_room		*shortest;

	anthill = ft_get_anthill();
	if (!anthill || !(shortest = no_way_to_end(anthill)))
		ft_printf("ERROR\n");
	else
	{
		for (t_room *act = anthill; act; act = act->next)
			ft_printf("ANTHILL %s\n", act->name);
			ft_printf("\n\n");
		for (t_room *act = shortest; act; act = act->parent)
			ft_printf("SHORTEST %s\n", act->name);
free_all_room(anthill);
	}
return (0);
}
