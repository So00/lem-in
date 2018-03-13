/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:16:43 by atourner          #+#    #+#             */
/*   Updated: 2018/03/13 16:27:19 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "lem.h"

void		push_first(t_room *all_path, int *act_ant, int *arrived)
{
	t_room	*actPath;

	actPath = all_path;
	if (all_path->start)
	{
		while (actPath && all_path->start)
		{
			if (actPath->len <= all_path->start || actPath == all_path)
			{
				actPath->next->act_ant = *act_ant;
				all_path->start--;
				ft_printf("L%d-%s ", *act_ant, actPath->next->name);
				*act_ant += 1;
				if (actPath->next->end)
					*arrived += 1;
			}
			actPath = actPath->parent;
		}
	}
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
			{
				ft_printf("L%d-%s ", room->act_ant, room->next->name);
				room->next->next_ant = room->act_ant;
				room->act_ant = room->next_ant;
				room->next_ant = 0;
				if (room->next->end)
					*arrived += 1;
			}
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
/*	while (all_path)
	{
		free_all_room(all_path);
		all_path = act;
		if (act)
			act = all_path->parent;
	}*/
}
