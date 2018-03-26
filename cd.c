/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:22:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/26 16:22:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void change_node_value(char *name, char *new_value)
{
	t_env_lst *list;

	list = vars;
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

int bi_cd(char **argv)
{
	char *home;
	char *old_pwd;
	char buf[MAXPATHLEN];

	if (!argv[1])
	{
		home = get_value_by_name("HOME");
		chdir(++home);
	}
	else if (ft_strequ(argv[1], "-"))
	{
		old_pwd = get_value_by_name("OLDPWD");
		chdir(++old_pwd);
	}
	else
		chdir(argv[1]);
	getcwd(buf, MAXPATHLEN);
	change_node_value("OLDPWD", ft_strdup(get_value_by_name("PWD")));
	change_node_value("PWD", ft_strjoin("=", buf));
	return (OK);
}