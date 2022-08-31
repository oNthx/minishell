/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:53:26 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/31 22:08:50 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <libft.h>

typedef struct	s_envp
{
	char			*key;
	char			*value;
	char			*fullstr;
	struct s_envp	*next;
}					t_envp;

typedef struct	s_process
{
	char				**path;
	t_envp				*envl;
	struct s_process	*next;
	struct s_process	*prev;
}						t_process;

/*
********************************ENV************************
*/
t_envp	*envp_new(char *str);
int		envp_size(t_envp *data);
void	envp_add_front(t_envp **data, t_envp *new);
void	envp_add_back(t_envp **data, t_envp *new);
void	envp_delone(t_envp *data);
void	envp_clear(t_envp *data);
//pars env
t_envp	*get_env(t_envp *envl, char *key);
t_process	*set_env(char *line);

/*
**************************BUILTIN*************************
*/
int	is_builtin(char *line);

#endif
