/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_struct_room.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 13:56:56 by atourner          #+#    #+#             */
/*   Updated: 2018/03/05 16:20:49 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"

static void	add_start_and_end(t_room *new, int *command, int ant_nb)
{
	if (*command == 1)
	{
		new->start = 1;
		*command = 0;
		new->ant_start = ant_nb;
	}
	else if (*command == 2)
	{
		new->end = 1;
		*command = 0;
	}
}

t_room		*create_room(char *to_parse, int *command, int ant_nb)
{
	t_room		*new;
	int			i;

	i = (int)ft_strlen(to_parse);
	if (!(new = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	ft_bzero(new, sizeof(t_room));
	new->next = NULL;
	while (ft_isdigit(to_parse[--i]))
		;
	new->position.y = ft_atoi(&to_parse[i + 1]);
	while (ft_isdigit(to_parse[--i]))
		;
	new->position.x = ft_atoi(&to_parse[i + 1]);
	new->name =  ft_strndup(to_parse, i);
	if (*command)
		add_start_and_end(new, command, ant_nb);
	return (new);
}

void		create_link(t_room *entry, t_room *out)
{
	t_link		*act;

	if (!entry->link)
		if (!(entry->link = ft_memalloc(sizeof(t_link))))
			return ;
	act = entry->link;
	while (act->next)
		act = act->next;
	act->room = out;
	if (!out->link)
		if (!(out->link = ft_memalloc(sizeof(t_link))))
			return ;
	act = out->link;
	while (act->next)
		act = act->next;
	act->room = entry;
}

void		free_room(t_room *act)
{
	ft_bzero(act, sizeof(t_room));
	free(act);
}

void		free_all_room(t_room *first)
{
	t_room	*next;

	next = first;
	while (next)
	{
		next = first->next;
		if (first->name)
			ft_strdel(&first->name);
		free_room(first);
		first = next;
	}
}
