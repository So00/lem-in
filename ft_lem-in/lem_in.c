/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:52:50 by atourner          #+#    #+#             */
/*   Updated: 2018/03/19 17:50:04 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"

void	get_next_path(t_room *shortest, t_room *anthill)
{
	t_room		*act_s;

	act_s = shortest;
	while (act_s->len < shortest->start
			&& (act_s->parent = no_way_to_end(anthill)))
	{
		reverse_room(&act_s->parent);
		free_room_used(anthill, act_s->parent);
		act_s = act_s->parent;
	}
}

int		main(int ac, char **av)
{
	t_room		*anthill;
	t_room		*shortest;
	t_room		*act;

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
		act = shortest;
		while (act)
		{
			shortest = shortest->parent;
			free_all_room(act);
			act = shortest;
		}
	}
	if (anthill)
		free_all_room(anthill);
	return (0);
}
