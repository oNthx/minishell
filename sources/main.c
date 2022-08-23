#include "../inc/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	char	**lines;

	while (1)
	{
		line = readline("Minishell$ ");
		if (!line)
			continue ;
		lines = ft_split(line, ' ');
		if (ft_strcmp(lines[0], "env") == 0)
			env(envp);
		else if (ft_strcmp(lines[0], "pwd") == 0)
			pwd();
		else if (ft_strcmp(lines[0], "cd") == 0)
			cd(lines);
		else
			printf("[ERROR] Comman not found\n");
		add_history(line);
		free(line);
		free_split(lines);
	}
}
