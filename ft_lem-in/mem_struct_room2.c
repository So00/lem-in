#include "lem.h"
#include "ft_printf.h"

/*void	free_link_used(t_link *act, t_room *anthill, char *name_of_room)
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
}*/

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
				ft_printf("Go in for actL->room->name [%s] && free [%s]\n", actL->room->name, name_of_free);
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
				ft_printf("je free [%s] dans [%s]\n", actL->room->name, act->name);
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

	actw = way;

/*	while (actw)
	{
		act = anthill;
		save = anthill;
		while (ft_strcmp(actw->name, act->name))
			act = act->next;
		if (act != anthill)
			while (save->next != act)
				save = save->next;
	}
*/
	//ANCIEN
/*	if (way->start && way->next->end)
	{
		actw = way;
		while (actw)
		{
			act = anthill;
			while (ft_strcmp(act->name, actw->name))
				act = act->next;
			free_link_used(act->link, anthill, act->name);
			actw = actw->next;
		}
	}
	else*/
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
