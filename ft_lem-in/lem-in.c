/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 10:49:58 by atourner          #+#    #+#             */
/*   Updated: 2018/03/15 12:08:19 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"

void	get_next_path(t_room *shortest, t_room *anthill)
{
	t_room		*act_S;

	act_S = shortest;
	while (act_S->len < shortest->start
			&& (act_S->parent = no_way_to_end(anthill)))
		{
			reverse_room(&act_S->parent);
			free_room_used(anthill, act_S->parent);
			act_S = act_S->parent;
		}
}

int		main(int ac, char **av)
{
	t_room		*anthill;
	t_room		*shortest;

	anthill = ft_get_anthill();
	if (!anthill || !(shortest = no_way_to_end(anthill)))
		ft_printf("ERROR\n");
	else
	{
		reverse_room(&shortest);
		free_room_used(anthill, shortest);
		if (ac == 1 || ft_strcmp(av[1], "-S"))
			get_next_path(shortest, anthill);
		solve(shortest);
	}
	if (anthill)
		free_all_room(anthill);
	return (0);
}
