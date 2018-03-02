/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 10:50:45 by atourner          #+#    #+#             */
/*   Updated: 2018/03/02 16:06:44 by atourner         ###   ########.fr       */
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
t_room			*create_room(char *to_parse, int *command);
void			free_all_room(t_room *first);
char			*ft_delete_part(char *to_delete, char *search);
int				start_link(t_room *first, char *str);
int				valid_room(char *tmp);
int				get_ant_nb(char **to_get);
void			get_command(char *str, int *command);
void			do_link(t_room *first, char **room, int ant_nb, int i);

#endif
