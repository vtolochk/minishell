/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:26:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/25 15:26:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env_lst *find_name(char *name)
{
	t_env_lst *lst;

	lst = vars;
	while (lst)
	{
		if (ft_strequ(name, lst->name))
		{
			ft_strdel(&(lst->value));
			return (lst);
		}
		lst = lst->next;
	}
	return (NULL);
}

static void change_list(char **argv, char **name)
{
	t_env_lst   *new_var;
	t_env_lst   *find;

	find = find_name(*name);
	if (find)
	{
		find->value = ft_strsub(argv[1], ft_strlen(*name), ft_strlen(argv[1]) - ft_strlen(*name));
		ft_strdel(name);
	}
	else
	{
		new_var = new_node();
		new_var->name = *name;
		new_var->value = ft_strsub(argv[1], ft_strlen(*name), ft_strlen(argv[1]) - ft_strlen(*name));
		list_push_back(new_var);
	}
}

int bi_setenv(char **argv)
{
	char        *sign;
	char        *name;


	if (!(argv[1]) || !(ft_strchr(argv[1], '=')) || argv[1][0] == '=' || argv[2] || count_sign(argv[1], '=') > 1)
	{
		write(2, "Usage: setenv [NAME]=[VALUE]\n", 31);
		return (FAIL);
	}
	else
	{
		remove_quotes(&argv[1]);
		sign = ft_strchr(argv[1], '=');
		name = ft_strsub(argv[1], 0, sign - argv[1]);
		if (ft_strequ(name, "PWD") || ft_strequ(name, "HOME") || ft_strequ(name, "OLDPWD") ||
			ft_strequ(name, "LANG") || ft_strequ(name, "SHELL") || ft_strequ(name, "USER") ||
			ft_strequ(name, "LOGNAME") || ft_strequ(name, "SHLVL"))
		{
			write(2, "The following variables cannot be changed: LANG, PWD, SHELL, USER, LOGNAME, SHLVL, OLDPWD.\n", 94);
			ft_strdel(&name);
			return (FAIL);
		}
		change_list(argv, &name);
	}
	return (OK);
}