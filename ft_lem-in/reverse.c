/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:59:09 by atourner          #+#    #+#             */
/*   Updated: 2018/03/15 14:59:10 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"

int		len_of_path(t_room *path)
{
	t_room	*act;
	int		i;

	i = 0;
	act = path;
	while (act)
	{
		i++;
		act = act->next;
	}
	return (i - 1);
}

void	reverse_room(t_room **to_reverse)
{
	t_room		*last;
	t_room		*first;
	t_room		*tmp;

	last = *to_reverse;
	while (last->parent)
		last = last->parent;
	first = *to_reverse;
	first->next = NULL;
	*to_reverse = last;
	last->next = NULL;
	tmp = *to_reverse;
	while (tmp)
	{
		last = first;
		if (!last->parent)
			break ;
		while (last->parent && ft_strcmp(last->parent->name, tmp->name))
			last = last->parent;
		tmp->next = last;
		last->parent = NULL;
		tmp = tmp->next;
	}
	(*to_reverse)->len = len_of_path(*to_reverse);
}
