/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:16:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/04/18 20:36:39 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		bi_env(char **argv)
{
	if (!argv[1])
		print_list();
	else
	{
		write(2, "Usage: env\n", 12);
		return (FAIL);
	}
	return (OK);
}

void	if_else_help(char **path, int *ret, char **argv, char *file)
{
	if (access(*path, X_OK) == -1)
	{
		ft_printf("minishell: permission denied: %s\n", file);
		ft_strdel(path);
	}
	else if (is_dir(*path))
	{
		ft_printf("%s cannot execute [It is a directory]\n", *path);
		ft_strdel(path);
	}
	else
		new_process(*path, argv);
	*ret = OK;
}
