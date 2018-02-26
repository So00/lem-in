/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_anthill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:30:29 by atourner          #+#    #+#             */
/*   Updated: 2018/02/26 16:32:19 by atourner         ###   ########.fr       */
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
	char	**separate_tmp;
	int		len;

	len = 0;
	if (tmp[0] == '#')
		return (2);
	separate_tmp = ft_strsplit_space(tmp);
	while (separate_tmp[len])
		len++;
	if (len < 3)
		len = 0;
	else if (ft_isstrdigit(separate_tmp[len - 1]) && ft_isstrdigit(separate_tmp[len - 2]))
		len = 1;
	else
		len = 0;
	ft_free_ar(separate_tmp);
	return (len);
}

static	t_room	*parse(char *to_get)
{
	t_room	*new;
	char	*tmp;

	if (!(new = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	ft_bzero(new, sizeof(t_room));
	if (to_get == "##start")
		t_room->start = 1;
	if (to_get == "##end")
		t_room->end = 1;
}

t_room			*ft_get_anthill()
{
	char	*tmp;
	int		ant_nb;
	t_room	*first;
	int		comment;

	ant_nb = 0;
	first = NULL;
	while (get_next_line(0, &tmp) && !ant_nb)
	{
		ant_nb = get_ant_nb(tmp);
		ft_strdel(&tmp);
	}
	while (ant_nb > 0 && get_next_line(0, tmp))
	{
		if ((comment = valid_room(tmp)))
				parse(first, tmp, ant_nb);
		else
			break ;
			ft_strdel(tmp);
	}
	if (tmp)
		ft_strdel(tmp);
	return (first);
}
