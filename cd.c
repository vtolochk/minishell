/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:22:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/04/18 20:33:19 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		check_perm_and_existence(char **argv, char *tild_sub)
{
	struct stat buf;

	if (argv[1] && argv[2])
	{
		ft_printf("cd: too many arguments\n");
		return (FAIL);
	}
	else if (lstat(tild_sub ? tild_sub : argv[1], &buf) == -1)
	{
		ft_printf("cd: no such file or directory: %s\n", \
		tild_sub ? tild_sub : argv[1]);
		return (FAIL);
	}
	else if (!(buf.st_mode & S_IXUSR))
	{
		ft_printf("cd: permission denied: %s\n", \
		tild_sub ? tild_sub : argv[1]);
		return (FAIL);
	}
	else if (S_ISREG(buf.st_mode))
	{
		ft_printf("cd: not a directory: %s\n", tild_sub ? tild_sub : argv[1]);
		return (FAIL);
	}
	return (OK);
}

static char		*substitute_tild(char *path)
{
	char *find;
	char *home;
	char *new_path;

	home = get_value_by_name("HOME");
	find = ft_strchr(path, '~');
	find++;
	if (!(*find))
		return (NULL);
	new_path = ft_strjoin(++home, find);
	return (new_path);
}

static int		regular_case(char **argv)
{
	char *f;
	char *new_path;

	if ((f = ft_strchr(argv[1], '~')) && ((*(f + 1) == '/') ||
	(*(f + 1) == ' ' || (*(f + 1) == '\t'))))
	{
		new_path = substitute_tild(argv[1]);
		if (check_perm_and_existence(argv, new_path) == OK)
			chdir(new_path);
		else
		{
			ft_strdel(&new_path);
			return (FAIL);
		}
		ft_strdel(&new_path);
	}
	else
	{
		if (check_perm_and_existence(argv, NULL) == OK)
			chdir(argv[1]);
		else
			return (FAIL);
	}
	return (OK);
}

int				bi_cd(char **argv)
{
	char		*home;
	char		*old_pwd;
	char		buf[MAXPATHLEN];

	if (!argv[1] || (ft_strequ(argv[1], "~") && !argv[2]))
	{
		home = get_value_by_name("HOME");
		chdir(++home);
	}
	else if (ft_strequ(argv[1], "-") && !argv[2])
	{
		old_pwd = get_value_by_name("OLDPWD");
		if (check_perm_and_existence(argv, ++old_pwd) == OK)
			chdir(old_pwd);
		else
			return (FAIL);
	}
	else if (regular_case(argv) == FAIL)
		return (FAIL);
	getcwd(buf, MAXPATHLEN);
	change_node_value("OLDPWD", ft_strdup(get_value_by_name("PWD")));
	change_node_value("PWD", ft_strjoin("=", buf));
	return (OK);
}
