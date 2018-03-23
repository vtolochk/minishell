/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 20:09:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/22 20:16:44 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/includes/libft.h"

#define OK 0
#define FAIL 1

typedef struct s_envlst
{
	char *name;
	char *value;
	struct s_envlst	*next;
}               t_envlst;

void print_list(t_envlst *list);
t_envlst *allocate_node(void);
t_envlst *copy_env(char **envp);
void run_commands(char **command, t_envlst *list);
void free_list(t_envlst **list);

#endif
