#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*str;
	char	*tmp;
	FILE	*fd;
	FILE	*ftmp;
	int		i;

	if (!(tmp = malloc(sizeof(char) * 100)))
	{
		printf("Error in malloc, please retry\n");
		return (0);
	}
	fd = fopen("normal.txt", "a");
	get_next_line(0, &str);
	i = 0;
	if (!ft_strcmp(str, "ERROR"))
	{
		free(str);
		printf("\033[0;31m🀫\033[0;0m");
		fprintf(fd, "Test %s returned Error\n", av[1]);
	}
	else
{
		free(str);
		for (i = 1; get_next_line(0, &str); i++)
			free(str);
		ftmp = fopen(av[1], "r");
		fgets(tmp, 100, ftmp);
		int		best = atoi(&tmp[1]);
		fgets(tmp, 100, ftmp);
		int		shortest = atoi(&tmp[1]);
		if (i == best)
			printf("\033[0;32m🀫\033[0;0m");
		else
		{
			printf("\033[0;33m🀫\033[0;0m");
			fprintf(fd, "Test %s\n not optimal\nNeeded move optimum : [%d]\nNeeded move only took shortest path : [%d]\n You did it in [%d] moves\n\n", av[1], best, shortest, i);
		}
		fclose(ftmp);
	}
	fclose(fd);
	free(tmp);
	return (0);
}
