/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:02:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/23 15:02:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_list(void)
{
	t_env_lst *ptr;

	while (g_vars)
	{
		ft_strdel(&(g_vars->name));
		ft_strdel(&(g_vars->value));
		ptr = g_vars;
		g_vars = g_vars->next;
		free(ptr);
	}
}

int list_len(t_env_lst *lst)
{
	int len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

t_env_lst *new_node(void)
{
	t_env_lst *node;

	node = (t_env_lst *)malloc(sizeof(t_env_lst));
	node->name = NULL;
	node->value = NULL;
	node->next = NULL;
	return (node);
}

char *get_value_by_name(char *name)
{
	char *value;
	t_env_lst *list;

	value = NULL;
	list = g_vars;
	while (list)
	{
		if (ft_strequ(name, list->name))
		{
			value = list->value;
			break ;
		}
		list = list->next;
	}
	return (value);
}

int remove_node(char *name)
{
	t_env_lst *list;
	t_env_lst *temp;

	list = g_vars;
	while (list->next)
	{
		if (ft_strequ(list->next->name, name))
		{
			ft_strdel(&list->next->name);
			ft_strdel(&list->next->value);
			temp = list->next;
			list->next = list->next->next;
			free(temp);
			break ;
		}
		list = list->next;
	}
	return (OK);
}

char **list_to_array(void)
{
	int i;
	char **envp;
	t_env_lst *list;

	i = 0;
	list = g_vars;
	envp = (char **)malloc(sizeof(char *) * ((list_len(list) + 1)));
	while (list)
	{
		envp[i++] = ft_strjoin(list->name, list->value);
		list = list->next;
	}
	envp[i] = NULL;
	return (envp);
}

void list_push_back(t_env_lst *new_node)
{
	t_env_lst *list;

	list = g_vars;
	while (list->next)
		list = list->next;
	list->next = new_node;
}

void print_list(void)
{
	t_env_lst *list;

	list = g_vars;
	while (list)
	{
		ft_printf("%s%s\n", list->name, list->value);
		list = list->next;
	}
}