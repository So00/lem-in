/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:01:56 by atourner          #+#    #+#             */
/*   Updated: 2018/02/26 16:07:16 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
