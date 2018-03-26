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

	while (vars)
	{
		ft_strdel(&(vars->name));
		ft_strdel(&(vars->value));
		ptr = vars;
		vars = vars->next;
		free(ptr);
	}
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
	list = vars;
	while (list)
	{
		if (ft_strequ(name, list->name))
			value = list->value;
		list = list->next;
	}
	return (value);
}

int remove_node(char *name)
{
	t_env_lst *list;
	t_env_lst *temp;

	list = vars;
	while (list->next)
	{
		if (ft_strequ(list->next->name, name))
		{
			ft_strdel(&list->next->name);
			ft_strdel(&list->next->value);
			temp = list->next;
			list->next = list->next->next;
			free(temp);
			continue ;
		}
		list = list->next;
	}
	return (OK);
}

char **list_to_array(void)
{
	return (NULL);
}

void list_push_back(t_env_lst *new_node)
{
	t_env_lst *list;

	list = vars;
	while (list->next)
		list = list->next;
	list->next = new_node;
}

void print_list(void)
{
	t_env_lst *list;

	list = vars;
	while (list)
	{
		ft_printf("%s%s\n", list->name, list->value);
		list = list->next;
	}
}