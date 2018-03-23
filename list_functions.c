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

void free_list(t_envlst **list)
{
	t_envlst *ptr;

	while (*list)
	{
		ft_strdel(&((*list)->name));
		ft_strdel(&((*list)->value));
		ptr = (*list);
		*list = (*list)->next;
		free(ptr);
	}
}

t_envlst *allocate_node(void)
{
	t_envlst *node;

	node = (t_envlst *)malloc(sizeof(t_envlst));
	node->name = NULL;
	node->value = NULL;
	node->next = NULL;
	return (node);
}

void print_list(t_envlst *head)
{
	while (head->next)
	{
		ft_printf("name: %s\n", head->name);
		ft_printf("value: %s\n", head->value);
		head = head->next;
	}
}