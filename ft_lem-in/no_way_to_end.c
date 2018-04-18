/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_way_to_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:18:04 by atourner          #+#    #+#             */
/*   Updated: 2018/04/17 13:51:41 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "lem.h"

static t_room	*cpy_room(t_room *to_cpy)
{
	t_room		*new;
	t_link		*act_l;

	if (!(new = malloc(sizeof(t_room))))
		return (NULL);
	act_l = to_cpy->link;
	ft_memcpy(new, to_cpy, sizeof(t_room));
	new->name = ft_strdup(to_cpy->name);
	new->link = NULL;
	while (act_l)
	{
		create_link(new, act_l->room);
		act_l = act_l->next;
	}
	new->next = NULL;
	new->parent = NULL;
	return (new);
}

static int		ft_closed(t_room *to_add, t_room *closed)
{
	t_room		*act;

	act = closed;
	while (act)
	{
		if (!strcmp(act->name, to_add->name))
			return (1);
		act = act->next;
	}
	return (0);
}

static void		add_all_next(t_room *open, t_room *closed)
{
	t_link	*act;
	t_room	*add;

	act = open->link;
	add = open;
	while (add->next)
		add = add->next;
	while (act)
	{
		if (!ft_closed(act->room, closed))
		{
			add->next = cpy_room(act->room);
			add = add->next;
			add->parent = open;
		}
		act = act->next;
	}
}

static void		add_to_close(t_room **act, t_room **closed, t_room **open)
{
	if (!*closed)
	{
		*closed = *open;
		*act = *closed;
	}
	else
	{
		(*act)->next = *open;
		*act = (*act)->next;
	}
}

t_room			*no_way_to_end(t_room *anthill)
{
	t_room				*open;
	t_room				*closed;
	t_room				*act;

	act = NULL;
	open = anthill;
	while (!open->start)
		open = open->next;
	open = cpy_room(open);
	closed = NULL;
	while (open)
	{
		add_all_next(open, closed);
		if (open->end)
		{
			free_room_if(open, closed);
			return (open);
		}
		add_to_close(&act, &closed, &open);
		open = open->next;
	}
	free_all_room(open);
	free_all_room(closed);
	return (NULL);
}
