#include "../../inc/minishell.h"

void	cd(char **line)
{
	char	*tmp;

	chdir(line[1]);
	tmp = getenv("PWD");
	setenv("OLDPWD", tmp, ft_strlen(tmp));
	printf("env: %s\n", getenv("OLDPWD"));
	tmp = getcwd(0, 0);
	setenv("PWD", tmp, ft_strlen(tmp));
	free(tmp);
}
