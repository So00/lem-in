/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:35:53 by atourner          #+#    #+#             */
/*   Updated: 2018/03/06 14:41:51 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"

void		create_link(t_room *entry, t_room *out)
{
	t_link		*act;

	if (!entry->link)
	{
		if (!(entry->link = ft_memalloc(sizeof(t_link))))
			return ;
		entry->link->room = out;
	}
	else
	{
		act = entry->link;
		while (act->next)
			act = act->next;
		if (!(act->next = ft_memalloc(sizeof(t_link))))
			return ;
		act->next->room = out;
	}
	if (!out->link)
	{
			if (!(out->link = ft_memalloc(sizeof(t_link))))
				return ;
		out->link->room = entry;
	}
	else
	{
		act = out->link;
		while (act->next)
			act = act->next;
		if (!(act->next = ft_memalloc(sizeof(t_link))))
			return ;
		act->next->room = entry;
	}
}


