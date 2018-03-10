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
	t_room		*act_S;

	anthill = ft_get_anthill();
	if (!anthill || !(shortest = no_way_to_end(anthill)))
		ft_printf("ERROR\n");
	else
	{
		reverse_room(&shortest);
		free_room_used(anthill, shortest);
		act_S = shortest;
		while ((act_S->parent = no_way_to_end(anthill)))
		{
			reverse_room(&act_S->parent);
			free_room_used(anthill, act_S->parent);
			act_S = act_S->parent;
		}
		for (t_room *act = anthill; act; act = act->next)
			ft_printf("ANTHILL %s\n", act->name);
		ft_printf("\n\n");
		int i = 0;
		for (act_S = shortest; act_S; act_S = act_S->parent, i++)
		{
			for (t_room *act = act_S; act; act = act->next)
				ft_printf("shortest %d  %s\n", i, act->name);
		}
	}
	if (anthill)
		free_all_room(anthill);
return (0);
}
