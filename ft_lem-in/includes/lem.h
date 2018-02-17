/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 10:50:45 by atourner          #+#    #+#             */
/*   Updated: 2018/02/17 09:58:11 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

typedef struct	s_position
{
	int		x;
	int		y;
}				t_position;

typedef struct	s_room
{
	char		*name;
	t_position	position;
	int			start;
	int			ant;
	int			end;
	t_position	link;
	s_room		*next;
}				t_room;

char			**ft_get_anthill();

#endif
