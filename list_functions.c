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

void free_list(t_env_lst **list)
{
	t_env_lst *ptr;

	while (*list)
	{
		ft_strdel(&((*list)->name));
		ft_strdel(&((*list)->value));
		ptr = (*list);
		*list = (*list)->next;
		free(ptr);
	}
}

t_env_lst *allocate_node(void)
{
	t_env_lst *node;

	node = (t_env_lst *)malloc(sizeof(t_env_lst));
	node->name = NULL;
	node->value = NULL;
	node->next = NULL;
	return (node);
}

char *get_value_by_name(t_env_lst *list, char *name)
{
	char *value;

	value = NULL;
	while (list)
	{
		if (ft_strequ(name, list->name))
			value = list->value;
		list = list->next;
	}
	return (value);
}

char **list_to_array(t_env_lst *list)
{
	(void)list;
	return (NULL);
}

void print_list(t_env_lst *head)
{
	while (head->next)
	{
		ft_printf("%s%s\n", head->name, head->value);
		head = head->next;
	}
}