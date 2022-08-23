#ifndef	MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "../libft/sources/libft.h"

/*
**************************STRUCTS*************************
*/

typedef struct	s_env
{
	char			*key;
	char			*value;
	char			*fullstr;
	struct s_env	*next;
}	t_env;

/*
************************DATA_STRUCTS**********************
*/
/*****ENV*****/
static char	*envl_join(char *key, char *value);
static int	envcmp(char *s1, char *s2);
t_env		*construct(char **envp);
t_env		*envpnew(char *str);
void		update_envp(char *key, char *value, t_env *envl);
void		envpadd_back(t_env **lst, t_env *new);
void		envpclear(t_env *envl);
void		envpdelone(t_env *lst, void (*del)(void *));
void		setenv(t_process *process);
int		envpsize(t_env *lst);
char		*getenv(char *name, t_env *envl);

/*
***********************COMMANDS***************************
*/
void	env(char **envp);
void	cd(char **line);
void	pwd();

/*
**************************PARSER**************************
*/
void	free_split(char **line);

#endif
