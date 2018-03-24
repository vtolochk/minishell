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

typedef struct s_env_lst
{
	char *name;
	char *value;
	struct s_env_lst	*next;
}               t_env_lst;

void print_list(t_env_lst *list);
t_env_lst *allocate_node(void);
t_env_lst *copy_env(char **envp);
char *get_value_by_name(t_env_lst *list, char *name);
void free_list(t_env_lst **list);
void run_commands(char **command, t_env_lst *list);
void new_process(char *process, char **argv);
char **list_to_array(t_env_lst *list);
int builtin_echo(char **argv);
int builtin_env(char **argv, t_env_lst *list);

#endif
