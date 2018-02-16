/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:16:47 by atourner          #+#    #+#             */
/*   Updated: 2018/02/12 14:57:13 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_cpy_realloc(char *buff, int len, char *file_read)
{
	char	*new;
	int		i;
	int		j;

	j = -1;
	i = -1;
	buff[len] = '\0';
	if (!(new = ft_strnew((len + ft_strlen(file_read) + 2))))
		return (NULL);
	while (file_read[++i])
		new[i] = file_read[i];
	free(file_read);
	while (++j < len)
		new[i + j] = buff[j];
	new[i + j] = '\0';
	ft_bzero(buff, BUFF_SIZE + 1);
	return (new);
}

static void		cpy_save(t_sav_str *act, char **file_read)
{
	ft_strcpy(*file_read, act->buff);
	free(act->buff);
	act->buff = NULL;
	act->len = 0;
}

static char		*ft_cpy_malloc(char *str, char c, int fre)
{
	char	*new;
	int		i;

	i = -1;
	if (!(new = ft_strnew(ft_strlen(str))))
		return (NULL);
	while (str[++i] && str[i] != c)
		new[i] = str[i];
	new[i] = '\0';
	if (fre)
		free(str);
	return (new);
}

static int		exit_gnl(char **to_free, char **line)
{
	free(*to_free);
	*line = NULL;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char				*file_read;
	int					d;
	char				buff[BUFF_SIZE + 1];
	static t_sav_str	save[4865];

	if (fd < 0 || !line || fd > 4864 || !(file_read = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (save[fd].len)
		cpy_save(&save[fd], &file_read);
	while (!ft_strchr(file_read, '\n') && (d = read(fd, buff, BUFF_SIZE)))
		if (d < 0 || !(file_read = ft_cpy_realloc(buff, d, file_read)))
			return (-1);
	if (!file_read[0] && d == 0)
		return (exit_gnl(&file_read, line));
	if ((*line = ft_strchr(file_read, '\n')))
	{
		if (!(save[fd].buff = ft_cpy_malloc(&line[0][1], '\0', 0)))
			return (-1);
		save[fd].len = ft_strlen(save[fd].buff);
	}
	*line = ft_cpy_malloc(file_read, '\n', 1);
	return (1);
}
