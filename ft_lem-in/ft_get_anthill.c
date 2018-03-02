/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_anthill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:30:29 by atourner          #+#    #+#             */
/*   Updated: 2018/03/02 16:06:14 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"

static char		**realloc_ar(char **tmp, char **act, int nb)
{
	char		**new;
	int			to_cpy;

	if (!(new = (char**)malloc(sizeof(char*) * (nb + 1))))
		return (NULL);
	to_cpy = -1;
	while (++to_cpy < nb - 1)
		new[to_cpy] = ft_strdup(act[to_cpy]);
	new[to_cpy] = ft_strdup(*tmp);
	new[to_cpy + 1] = NULL;
	if (act)
		ft_free_ar((void**)act);
	ft_strdel(tmp);
	return (new);
}

static void	parse_room(char *to_parse, t_room **first, int *command)
{
	t_room	*act;

	if (!*first)
		*first = create_room(to_parse, command);
	else
	{
		act = *first;
		while (act->next)
			act = act->next;
		act->next = create_room(to_parse, command);
	}
}

static	t_room	*parse(char **room, int command, int ant_nb)
{
	t_room		*ret;
	int			i;
	int			need_parse;

	i = -1;
	ret = NULL;
	while (room[++i])
	{
		if (!(need_parse = valid_room(room[i])))
		{
			if (start_link(ret, ft_strdup(room[i])))
				break;
			free_all_room(ret);
			return (NULL);
		}
		if (need_parse != 2)
			parse_room(room[i], &ret, &command);
		get_command(room[i], &command);
	}
	do_link(ret, room, ant_nb, i);
	return (ret);
}

t_room			*ft_get_anthill()
{
	char	*tmp;
	int		ant_nb;
	char	**act;
	int		nb;
	t_room	*first;

	ant_nb = 0;
	nb = 0;
	act = NULL;
	while (!ant_nb && get_next_line(0, &tmp))
		ant_nb = get_ant_nb(&tmp);
	while (ant_nb > 0 && get_next_line(0, &tmp))
		act = realloc_ar(&tmp, act, ++nb);
	first = parse(act, 0, ant_nb);
//	ft_free_ar((void**)act);
	return (first);
}
