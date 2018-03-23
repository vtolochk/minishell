/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:39:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/23 12:39:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int get_index(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	if (str[0] == '\0')
		return (-1);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

t_envlst *copy_env(char **envp)
{
	int i;
	int index;
	t_envlst *list;
	t_envlst *head;

	i = 0;
	list = allocate_node();
	head = list;
	while (envp[i])
	{
		index = get_index(envp[i], '=');
		if (index == -1)
			break ;
		list->name = ft_strsub(envp[i], 0, index);
		list->value = ft_strsub(envp[i], index + 1, ft_strlen(envp[i]) - index);
		list->next = allocate_node();
		list = list->next;
		i++;
	}
	return (head);
}