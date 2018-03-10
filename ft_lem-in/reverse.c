#include "lem.h"
#include "ft_printf.h"

void	reverse_room(t_room **to_reverse)
{
	t_room		*last;
	t_room		*first;
	t_room		*tmp;

	last = *to_reverse;
	while (last->parent)
		last = last->parent;
	first = *to_reverse;
	first->next = NULL;
	*to_reverse = last;
	last->next = NULL;
	tmp = *to_reverse;
	while (tmp)
	{
		last = first;
		if (!last->parent)
			break;
		while (last->parent && ft_strcmp(last->parent->name, tmp->name))
			last = last->parent;
		tmp->next = last;
		last->parent = NULL;
		tmp = tmp->next;
	}
}