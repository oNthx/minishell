/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 10:22:39 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/28 15:14:40 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <libft.h>

/*
****************************STRUCTS*****************************
*/
//**********************ENV************************
typedef struct s_envp
{
	char			*key;
	char			*value;
	char			*fullstr;
	struct s_envp	*next;
}					t_envp;
//********************PROCESS**********************
typedef struct s_process
{
	pid_t				pid;
	char				*name;
	char				*path;
	char				**args;
	t_envp				*envp;
	t_stdfd				*stdfd;
	t_redirect			*redirect;
	struct s_process	*next;
	struct s_process	*prev;
}						t_process;
/*
****************************BUILTIN***************************
*/
char	*pwd();
void	unset(t_process *head_ref);

/*
****************************DATA_STRUCT*************************
*/
//**********************ENVP_DATA*******************
void	envp_add_back(t_envp **lst, t_envp *new);
void	envp_add_front(t_envp **lst, t_envp *new);
void	envp_delone(t_envp *envp, void (*del)(void *));
void	envp_clear(t_envp *envl);
t_envp	*envp_new(char *str);
int		envp_size(t_envp *envl);
void	set_env(t_process *process);
t_envp	*get_env(char **envl, t_envp *data);

/*
******************************SOURCES**************************
*/
int	contains_char(char *str, char c);
int	check_env(char *env_name);

#endif
