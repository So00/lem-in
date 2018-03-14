#include "lem.h"
#include "ft_printf.h"

void	free_link_used(t_room *anthill, char *name_of_free)
{
	t_room	*act;
	t_link	*bef;
	t_link	*actL;

	act = anthill;
	while (act)
	{
		actL = act->link;
		while (actL)
		{
			if (!ft_strcmp(actL->room->name, name_of_free))
			{
				if (actL == act->link)
				{
					act->link = actL->next;
					bef = act->link;
				}
				else
				{
					bef = act->link;
					while (bef->next != actL)
						bef = bef->next;
					bef->next = actL->next;
				}
				free (actL);
				actL = bef;
			}
			if (actL)
				actL = actL->next;
		}
		act = act->next;
	}
}

void	free_room_used(t_room *anthill, t_room *way)
{
	t_room		*save;
	t_room		*act;
	t_room		*actw;
	t_link		*actL;
	t_link		*old;

	actw = way;
	if (way->start && way->next->end)
	{
		actw = way;
		while (actw)
		{
			act = anthill;
			while (ft_strcmp(act->name, actw->name))
				act = act->next;
			actL = act->link;
			while (!actL->room->end && !actL->room->start)
			{
				old = actL;
				actL = actL->next;
			}
			old->next = actL->next;
			free(actL);
			actw = actw->next;
		}
	}
	else
	while (actw)
	{
		act = anthill;
		while (act)
		{
			if (!ft_strcmp(act->name, actw->name))
			{
				save = anthill;
				if (act != anthill)
					while (save->next != act)
						save = save->next;
				if (!act->end && !act->start)
				{
					free_link_used(anthill, actw->name);
					save->next = act->next;
					free_room(act);
					act = save;
				}
			}
			act = act->next;
		}
		actw = actw->next;
	}
}
