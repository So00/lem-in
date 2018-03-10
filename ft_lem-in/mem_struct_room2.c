#include "lem.h"
#include "ft_printf.h"

void	free_link_used(t_link *act, t_room *anthill, char *name_of_room)
{
	t_room	*actR;
	t_link	*actL;
	t_link	*Lto_free;
	t_link	*bef;

	actL = act;
	while (actL)
	{
		actR = anthill;
		while (ft_strcmp(actR->name, actL->room->name))
			actR = actR->next;
		Lto_free = actR->link;
		if (!ft_strcmp(Lto_free->room->name, name_of_room))
			actR->link = Lto_free->next;
		else
		{
			while (ft_strcmp(Lto_free->room->name, name_of_room))
				Lto_free = Lto_free->next;
			bef = actR->link;
			while (bef->next != Lto_free)
				bef = bef->next;
			bef->next = Lto_free->next;
		}
		free(Lto_free);
		if (actL)
			actL = actL->next;
	}
}

void	free_room_used(t_room *anthill, t_room *way)
{
	t_room		*save;
	t_room		*act;
	t_room		*actw;

	act = anthill;
	if (way->start && way->next->end)
		free_link_used(way->link, anthill, way->name);
	else
	while (act)
	{
		actw = way;
		while (actw)
		{
			if (!actw->start && !actw->end && !ft_strcmp(act->name, actw->name))
			{
				save = anthill;
				if (act != anthill)
					while (save->next != act)
						save = save->next;
				free_link_used(act->link, anthill, act->name);
				save->next = act->next;
				free(act);
			}
			actw = actw->next;
		}
		act = act->next;
	}
}
