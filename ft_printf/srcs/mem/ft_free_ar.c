/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 22:31:41 by atourner          #+#    #+#             */
/*   Updated: 2018/02/26 16:33:01 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_free_ar(void **mem)
{
	char	**str;
	int		i;

	i = -1;
	str = (char**)mem;
	while (str[++i])
		ft_strdel(&str[i]);
	free(str);
	str = NULL;
}
