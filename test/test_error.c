#include "ft_printf.h"

int	main(int ac, char **av)
{
	char *str;
	get_next_line(0, &str);
	if (!ft_strcmp(str, "ERROR"))
		ft_printf("test %s\n OK\n", av[1]);
	else
		ft_printf("test %s\n faux\nRéponse attendue : [Error]\nRéponse trouvée : [%s]\n", av[1], str);
	free(str);
	return (0);
}
