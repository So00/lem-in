/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_struct_room.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 13:56:56 by atourner          #+#    #+#             */
/*   Updated: 2018/02/27 14:36:18 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"

t_room		*create_room()
{
	t_room		*new;

	if (!(new = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	ft_bzero(new, sizeof(t_room));
	new->next = NULL;
	return (new);
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
		free_room(first);
		first = next;
	}
}
