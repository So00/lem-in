/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 10:50:45 by atourner          #+#    #+#             */
/*   Updated: 2018/02/27 14:35:56 by atourner         ###   ########.fr       */
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
	char				*name;
	t_position			position;
	int					start;
	int					ant;
	int					end;
	struct s_room		*next;
}				t_room;

t_room			*ft_get_anthill();
t_room			*create_room();
void			free_all_room(t_room *first);
void			ft_delete_part(char **to_delete, char *search);

#endif
