/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:16:43 by atourner          #+#    #+#             */
/*   Updated: 2018/03/15 15:21:11 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "lem.h"

void		push_first(t_room *all_path, int *act_ant, int *arrived)
{
	t_room	*act_path;

	act_path = all_path;
	if (all_path->start)
	{
		while (act_path && all_path->start)
		{
			if (act_path->len <= all_path->start || act_path == all_path)
			{
				act_path->next->act_ant = *act_ant;
				all_path->start--;
				ft_printf("L%d-%s ", *act_ant, act_path->next->name);
				*act_ant += 1;
				if (act_path->next->end)
					*arrived += 1;
			}
			act_path = act_path->parent;
		}
	}
}

void		push_act_room(t_room *room, int *arrived)
{
	ft_printf("L%d-%s ", room->act_ant, room->next->name);
	room->next->next_ant = room->act_ant;
	room->act_ant = room->next_ant;
	room->next_ant = 0;
	if (room->next->end)
		*arrived += 1;
}

void		push_in_lab(t_room *all_path, int *arrived)
{
	t_room	*path;
	t_room	*room;

	path = all_path;
	while (path)
	{
		room = path->next;
		while (!room->end)
		{
			if (room->act_ant)
				push_act_room(room, arrived);
			if (room->next_ant)
			{
				room->act_ant = room->next_ant;
				room->next_ant = 0;
			}
			room = room->next;
		}
		path = path->parent;
	}
}

void		solve(t_room *all_path)
{
	int		act_ant;
	int		arrived;
	int		nb_ant;

	act_ant = 1;
	arrived = 0;
	nb_ant = all_path->start;
	while (arrived != nb_ant)
	{
		push_in_lab(all_path, &arrived);
		push_first(all_path, &act_ant, &arrived);
		ft_printf("\n");
	}
}
