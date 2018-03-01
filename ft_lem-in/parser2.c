#include "ft_printf.h"

void		ft_delete_part(char **to_delete, char *search)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = ft_strstr(*to_delete, search);
	if (tmp == *to_delete)
	{
		if (!ft_strcmp(*to_delete, search))
			tmp = ft_strdup("\0");
		else
		{
			while ((*to_delete)[i] == search[i])
				i++;
			tmp = ft_strdup(&((*to_delete)[i + 1]));
		}
	}
	else
		tmp = ft_strdup(tmp);
	ft_strdel(to_delete);
	*to_delete = tmp;
}
