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

static t_room	**add_one(t_room **old)
{
	t_room	*new;


}

static t_room	**parse(char **to_get)
{
	t_room		**room;
	int			size;

	size = 2;
	if (!(room = (t_room**)malloc(sizeof(t_room*) * size)))
		return (NULL);
	
}

static char		**double_ar_realloc(char **old, char *tmp, int size)
{
	char	**ret;
	int		i;

	i = -1;
	if (!(ret = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	while (++i < size - 2)
		ret[i] = ft_strdup(old[i]);
	ret[i] = tmp;
	ret[i + 1] = NULL;
	if (old)
		ft_free_ar((void**)old);
	return (ret);
}

char			**ft_get_anthill()
{
	char	*tmp;
	char	**ret;
	int		size;

	ret = NULL;
	size = 1;
	while (get_next_line(0, &tmp) && ++size)
		ret = double_ar_realloc(ret, tmp, size);
	return (ret);
}
