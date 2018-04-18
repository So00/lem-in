/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:58:24 by atourner          #+#    #+#             */
/*   Updated: 2018/04/17 15:08:41 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "lem.h"

t_room		*search_arrival(t_room *first, char *str, char *to_free)
{
	t_room	*act;
	t_room	*ret;

	if (!first || !str)
	{
		ft_strdel(&to_free);
		return (0);
	}
	act = first;
	ret = NULL;
	while (act && !ret)
	{
		if (!(ft_strcmp(str, act->name)))
			ret = act;
		act = act->next;
	}
	ft_strdel(&to_free);
	return (ret);
}

int			free_if_needed(char *str)
{
	if (str)
		ft_strdel(&str);
	return (0);
}

int			start_link(t_room *first, char *str)
{
	t_room	*act;
	int		link;
	t_room	*out;
	char	*tmp;

	if (!first)
		return (free_if_needed(str));
	act = first;
	link = 0;
	while (act)
	{
		if (ft_strstr(str, act->name))
		{
			tmp = ft_strdup(str);
			if ((out = search_arrival(act->next,
							ft_delete_part(tmp, act->name), tmp)))
			{
				create_link(act, out);
				link++;
			}
		}
		act = act->next;
	}
	ft_strdel(&str);
	return (link);
}

char		*ft_delete_part(char *to_delete, char *search)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = best_chance(to_delete, search);
	if (tmp == to_delete)
	{
		if (!ft_strcmp(to_delete, search))
			return (NULL);
		while (to_delete[i] == search[i])
			i++;
		tmp = (to_delete[i] == '-' ? &to_delete[i + 1] : &to_delete[i]);
	}
	else
	{
		if (ft_strcmp(tmp, search))
			return (NULL);
		while (&to_delete[i + 1] != tmp)
			i++;
		to_delete[(to_delete[i] == '-' ? i : i + 1)] = '\0';
		tmp = to_delete;
	}
	return (tmp);
}

void		do_link(t_room *first, char **room, int i)
{
	int		continu;

	continu = 1;
	while (room[i] && continu)
	{
		if (room[i][0] != '#')
			continu = start_link(first, ft_strdup(room[i]));
		else if (!ft_strcmp(room[i], "##start") || !ft_strcmp(room[i], "##end"))
			break ;
		i++;
	}
}
