/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:02:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/30 21:40:57 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		free_list(void)
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

void		change_node_value(char *name, char *new_value)
{
	t_env_lst *list;

	list = g_vars;
	while (list)
	{
		if (ft_strequ(list->name, name))
		{
			ft_strdel(&(list->value));
			list->value = new_value;
			break ;
		}
		list = list->next;
	}
}

int			list_len(t_env_lst *lst)
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

t_env_lst	*new_node(void)
{
	t_env_lst *node;

	node = (t_env_lst *)malloc(sizeof(t_env_lst));
	node->name = NULL;
	node->value = NULL;
	node->next = NULL;
	return (node);
}

char		*get_value_by_name(char *name)
{
	char		*value;
	t_env_lst	*list;

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
