/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_anthill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:30:29 by atourner          #+#    #+#             */
/*   Updated: 2018/02/27 15:53:35 by atourner         ###   ########.fr       */
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

/*int		valid_room(char *tmp)
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
	else if (ft_isstrdigit(separate_tmp[len - 1])
			&& ft_isstrdigit(separate_tmp[len - 2]))
		len = 1;
	else
		len = 0;
	ft_free_ar((void**)separate_tmp);
	if (!len)
		ft_strdel(&tmp);
	return (len);
}*/

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

t_room			*ft_get_anthill()
{
	char	*tmp;
	int		ant_nb;
	char	**act;
	int		nb;
	t_room	*first;

	first = create_room();
	ant_nb = 0;
	nb = 0;
	act = NULL;
	while (!ant_nb && get_next_line(0, &tmp))
		ant_nb = get_ant_nb(&tmp);
	while (ant_nb > 0 && get_next_line(0, &tmp))
		act = realloc_ar(&tmp, act, ++nb);
	return (first);
}
