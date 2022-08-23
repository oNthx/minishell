#include "../../inc/minishell.h"

void	pwd()
{
	char	*str;

	str = getenv("PWD");
	printf("%s\n", str);
}

int	main()
{
	pwd();
}
