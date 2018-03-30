/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 18:31:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/30 21:14:11 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		validation(char **argv)
{
	if (!(argv[1]) || argv[1][0] == '=' || argv[2])
	{
		write(2, "Usage: unsetenv [NAME]\n", 24);
		return (FAIL);
	}
	return (OK);
}

int				bi_unsetenv(char **argv, t_env_lst *list)
{
	list = g_vars;
	if (validation(argv) == FAIL)
		return (FAIL);
	else
	{
		remove_quotes(&argv[1]);
		if (ft_strequ(argv[1], "PWD") || ft_strequ(argv[1], "HOME") ||
			ft_strequ(argv[1], "OLDPWD") || ft_strequ(argv[1], "USER") ||
			ft_strequ(argv[1], "LOGNAME") || ft_strequ(argv[1], "SHLVL"))
			return (FAIL);
		while (list)
		{
			if (ft_strequ(list->name, argv[1]))
				break ;
			list = list->next;
		}
		if (!list)
		{
			ft_printf("Can't find the variable %s.\n", argv[1]);
			return (FAIL);
		}
		remove_node(argv[1]);
	}
	return (OK);
}
