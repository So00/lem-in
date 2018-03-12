/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:16:43 by atourner          #+#    #+#             */
/*   Updated: 2018/03/12 16:21:04 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "lem.h"

void		solve(t_room *all_path)
{
	t_room	*act;

	act = all_path->parent;
	while (all_path)
	{
		free_all_room(all_path);
		all_path = act;
		if (act)
			act = all_path->parent;
	}
}
