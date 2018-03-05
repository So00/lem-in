/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:51:09 by atourner          #+#    #+#             */
/*   Updated: 2018/03/05 15:09:17 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"

int		test_anthill(t_room *first)
{
	t_room	*test;
	t_room	*act;
	int		check_begin_and_end;

	test = first;
	check_begin_and_end = 0;
	while (test)
	{
		act = test->next;
		while (act)
		{
			if (!strcmp(test->name, act->name))
				return (0);
			if (test->position.x == act->position.x && test->position.y == act->position.y)
				return (0);
			if ((test->start && act->start) || (test->end && act->end))
				return (0);
			act = act->next;
		}
		if (test->start || test->end)
			check_begin_and_end++;
		test = test->next;
	}
	if (check_begin_and_end != 2)
		return (0);
	return (1);
}
