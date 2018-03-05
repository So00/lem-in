/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:24:36 by atourner          #+#    #+#             */
/*   Updated: 2018/03/05 15:25:03 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "lem.h"

int		get_ant_nb(char **to_get)
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

void	get_command(char *str, int *command)
{
	if (*command && (!ft_strcmp("##start\0", str) || !ft_strcmp("##end\0", str)))
		*command = -1;
	else if (!ft_strcmp("##start\0", str))
		*command = 1;
	else if (!ft_strcmp("##end\0", str))
		*command = 2;
	else if (str[0] == '#' && str[1] == '#')
		*command = -1;
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