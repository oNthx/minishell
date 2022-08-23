#include "../../inc/minishell.h"

void	env(char *line)
{
	while (__environ && *__environ)
		printf("%s\n",*__environ++);
}
