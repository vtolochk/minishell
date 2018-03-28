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

int check_perm_and_existence(char **argv)
{
	struct stat buf;

	if (argv[1]  && argv[2])
	{
		ft_printf("cd: too many arguments\n");
		return (FAIL);
	}
	else if (lstat(argv[1], &buf) == -1)
	{
		ft_printf("cd: no such file or directory: %s\n", argv[1]);
		return (FAIL);
	}
	else if (!(buf.st_mode & S_IXUSR))
	{
		ft_printf("cd: permission denied: %s\n", argv[1]);
		return (FAIL);
	}
	else if (S_ISREG(buf.st_mode))
	{
		ft_printf("cd: not a directory: %s\n", argv[1]);
		return (FAIL);
	}
	return (OK);
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
	else if (ft_strequ(argv[1], "-") && !argv[2])
	{
		old_pwd = get_value_by_name("OLDPWD");
		chdir(++old_pwd);
	}
	else
	{
		if (check_perm_and_existence(argv) == OK)
			chdir(argv[1]);
		else
			return (FAIL);
	}
	getcwd(buf, MAXPATHLEN);
	change_node_value("OLDPWD", ft_strdup(get_value_by_name("PWD")));
	change_node_value("PWD", ft_strjoin("=", buf));
	return (OK);
}