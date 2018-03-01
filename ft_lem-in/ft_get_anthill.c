/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_anthill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:30:29 by atourner          #+#    #+#             */
/*   Updated: 2018/02/27 16:07:17 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"

static int		get_ant_nb(char **to_get)
{
	int		len;
	int		ret;

	len = (int)ft_strlen(*to_get);
	ret = 1;
	if (!strcmp(*to_get, "##start\0")
			|| !strcmp(*to_get, "##end\0") || !*to_get)
		ret = -1;
	if (ret > 0 && (*to_get)[0] == '#')
		ret = 0;
	if (ret > 0 && len > 10)
		ret = -1;
	if (ret > 0 && !ft_isstrdigit(*to_get))
		ret = -1;
	if (ret > 0 && len == 10 && ft_strcmp(*to_get, "2147483647\0") > 0)
		ret = -1;
	if (ret > 0)
		ret = ft_atoi(*to_get);
	ft_strdel(to_get);
	return (ret);
}

static int	start_link(t_room *first, char *str)
{
	t_room		*act;
	int			link;
	int			i;

	if (!first)
		return (0);
	act = first;
	link = 0;
	while (act)
	{
		if (ft_strstr(str, act->name))
		{
			ft_delete_part(&str, act->name);
			link++;
		}
		if (link == 2)
		{
		if (!*str)
			i = 1;
		else
			i = 0;
		ft_strdel(&str);
			return (i);
		}
		act = act->next;
	}
	ft_strdel(&str);
	return (0);
}

static int	valid_room(char *tmp)
{
	char	**separate_tmp;
	int		len;

	len = 0;
	if (tmp[0] == '#')
		return (2);
	separate_tmp = ft_strsplit_space(tmp);
	while (separate_tmp[len])
		len++;
	if (len < 3 || tmp[0] == 'L')
		len = 0;
	else if (ft_isstrdigit(separate_tmp[len - 1])
			&& ft_isstrdigit(separate_tmp[len - 2]))
		len = 1;
	else
		len = 0;
	ft_free_ar((void**)separate_tmp);
	return (len);
}

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

static int	parse_room(char *to_parse, t_room **first)
{
	int		i;
	t_room	*act;

	if (!*first)
		*first = create_room();
	else
		(*first)->next = create_room();
	act = ((*first)->next ? (*first)->next : *first);
	i = (int)ft_strlen(to_parse);
	while (ft_isdigit(to_parse[--i]))
		;
	act->position.y = ft_atoi(&to_parse[i + 1]);
	while (ft_isdigit(to_parse[--i]))
		;
	act->position.x = ft_atoi(&to_parse[i + 1]);
	act->name =  ft_strndup(to_parse, i);
	return (1);
}

static	t_room	*parse(char **room)
{
	t_room		*ret;
	int			i;
	t_room		*act;
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
			ft_free_ar((void**)room);
			return (NULL);
		}
		if (need_parse != 2)
		{
			if (!ret)
			{
				parse_room(room[i], &ret);
				act = ret;
			}
			else
			{
				parse_room(room[i], &act);
				act = act->next;
			}
		}
	}
	for (act = ret; act->next; act = act->next)
		ft_printf("%s %d %d\n", act->name, act->position.x, act->position.y);
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
	first = parse(act);
	if (!first)
		ft_printf("NULL\n");
	return (first);
}
