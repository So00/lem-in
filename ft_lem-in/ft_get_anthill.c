/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_anthill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:30:29 by atourner          #+#    #+#             */
/*   Updated: 2018/02/16 18:04:56 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"

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
