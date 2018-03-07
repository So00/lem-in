/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 10:49:58 by atourner          #+#    #+#             */
/*   Updated: 2018/03/07 13:47:07 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"

int		main()
{
	t_room		*anthill;
	int			shortest;

	anthill = ft_get_anthill();
	if (!anthill || !(shortest = no_way_to_end(anthill)))
		ft_printf("ERROR\n");
	else
	{
		free_all_room(anthill);
	}
return (0);
}
