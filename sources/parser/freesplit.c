#include "../../inc/minishell.h"

void	free_split(char **line)
{
	int	idx;

	idx = 0;
	while (line[idx])
		free(line[idx++]);
	free(line);
}
