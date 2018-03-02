/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:24:46 by atourner          #+#    #+#             */
/*   Updated: 2018/03/02 16:07:59 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "lem.h"

int		search_arrival(t_room *first, char *str)
{
	t_room	*act;
	char	*tmp;
	int		ret;

	if (!first || !str)
		return (0);
	act = first;
	ret = 0;
	while (act && !ret)
	{
		if (ft_strstr(str, act->name))
		{
			if (!(tmp = ft_delete_part(str, act->name)))
				ret = 1;
			else
				ft_strdel(&tmp);
		}
		act = act->next;
	}
	ft_strdel(&str);
	return (ret);
}

int		start_link(t_room *first, char *str)
{
	t_room	*act;
	int		link;

	if (!first)
		return (0);
	act = first;
	link = 0;
	while (act)
	{
		if (ft_strstr(str, act->name))
			if (search_arrival(act->next, ft_delete_part(str, act->name)))
				link++;
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
	tmp = ft_strstr(to_delete, search);
	if (tmp == to_delete)
	{
		if (!ft_strcmp(to_delete, search))
			return (NULL);
		else
		{
			while (to_delete[i] == search[i])
				i++;
			tmp = ft_strdup(&(to_delete[i + 1]));
		}
	}
	else
	{
		while (&to_delete[i + 1] != tmp)
			i++;
		tmp = ft_strndup(to_delete, i);
	}
	return (tmp);
}

void		do_link(t_room *first, char **room, int ant_nb, int i)
{
	while (room[i] && ant_nb)
	{
		ft_printf("[%s] [%s] [%d]\n", room[i], first->name, first->start);
		ft_printf("%d\n", ant_nb = start_link(first, room[i]));
		i++;
	}
}
