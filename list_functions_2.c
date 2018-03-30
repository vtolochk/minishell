/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:36:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/30 21:45:36 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			remove_node(char *name)
{
	t_env_lst		*list;
	t_env_lst		*temp;

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

char		**list_to_array(void)
{
	int			i;
	char		**envp;
	t_env_lst	*list;

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

void		list_push_back(t_env_lst *new_node)
{
	t_env_lst *list;

	list = g_vars;
	while (list->next)
		list = list->next;
	list->next = new_node;
}

void		print_list(void)
{
	t_env_lst *list;

	list = g_vars;
	while (list)
	{
		ft_printf("%s%s\n", list->name, list->value);
		list = list->next;
	}
}
