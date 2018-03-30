/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:49:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/30 21:50:42 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*get_first_part(char *str)
{
	char *part;
	char *find;

	find = ft_strrchr(str, '$');
	if (!find)
		find = ft_strchr(str, '=');
	part = ft_strsub(str, 0, find - str);
	return (part);
}

static void		create_new_str(int len, char *find, char *first, char **string)
{
	char		*temp[2];
	char		*str_find;
	t_env_lst	*list;

	while (len-- > 0)
	{
		list = g_vars;
		while (list)
		{
			if ((str_find = (ft_strstr(find, list->name))))
			{
				temp[0] = ft_strdup(list->value);
				temp[1] = temp[0];
				str_find = str_find + ft_strlen(list->name);
				*string = ft_strjoin(first, ++(temp[0]));
				ft_strdel(&temp[1]);
				temp[1] = *string;
				*string = ft_strjoin(*string, str_find);
				ft_strdel(&temp[1]);
				return ;
			}
			list = list->next;
		}
	}
}

char			*remove_dollar(char *argv)
{
	int		len;
	char	*string;
	char	*first_part;
	char	*find;

	string = NULL;
	first_part = get_first_part(argv);
	find = ft_strrchr(argv, '$');
	if (find)
	{
		len = ft_strlen(++find);
		create_new_str(len, find, first_part, &string);
	}
	else
	{
		find = ft_strrchr(argv, '=');
		string = ft_strjoin(first_part, find);
	}
	if (!string)
	{
		find = ft_strrchr(argv, '=');
		string = ft_strjoin(first_part, ++find);
	}
	ft_strdel(&first_part);
	return (string);
}
