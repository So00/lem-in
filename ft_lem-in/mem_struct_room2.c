#include "lem.h"
#include "ft_printf.h"

void	free_room_used(t_room *anthill, t_room *way)
{
	t_room		*save;
	t_room		*act;
	t_room		*actw;

	act = anthill;
	while (act)
	{
		actw = way;
		while (actw)
		{
			if (!actw->start && !actw->end && !ft_strcmp(act->name, actw->name))
			{
				save = anthill;
				while (save->next != act)
					save = save->next;
				save->next = act->next;
				free(act);
			}
			actw = actw->next;
		}
		act = act->next;
	}
}
