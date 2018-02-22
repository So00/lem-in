/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_anthill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:30:29 by atourner          #+#    #+#             */
/*   Updated: 2018/02/17 10:14:44 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"

static int		get_ant_nb(char *to_get)
{
	if (to_get[0] == '#')
		return (0);
	if (to_get[i][0] == '-' && ft_strlen(to_get[i]) >= 11
		&& ft_strcmp(to_get[i], "-2147483648\0") > 0)
		return (-1);
	if (ft_strlen(to_get[i] >= 10) && ft_strcmp(to_get[i], "2147483647\0") > 0)
		return (-1);
	return (ft_atoi(to_get[i]));
}

int		valid_room(char *tmp)
{
	if (!ft_strcmp(tmp, "##start"))
}

static	t_room	*parse(char *to_get)
{
	
}

t_room			*ft_get_anthill()
{
	char	*tmp;
	int		ant_nb;
	t_room	*first;
	t_room	*act;

	ant_nb = 0;
	first = NULL;
	while (get_next_line(0, &tmp) && !ant_nb)
	{
		ant_nb = get_ant_nb(tmp);
		ft_strdel(&tmp);
	}
	while (ant_nb > 0 && get_next_line(0, tmp))
	{
			if (first)
			{
				act->next = parse(tmp, ant_nb);
				act = act->next;
			}
			else
			{
				first = parse(tmp, ant_nb);
				act = first;
			}
		}
		ft_strdel(tmp);
	}
	return (first);
}
