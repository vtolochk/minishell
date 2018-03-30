/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:41:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/30 21:16:35 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		other_commands(char **argv, char **commands, char **ptr)
{
	if (ft_strequ(argv[0], "exit"))
	{
		ft_free_tab((void**)argv);
		ft_free_tab((void**)commands);
		free_list();
		ft_strdel(ptr);
		exit(OK);
	}
	else
	{
		if (execute_files(argv, FAIL) == FAIL)
			ft_printf("minishell: %s: command not found\n", argv[0]);
	}
}

void			choose_commands(char **argv, char **commands, char **ptr)
{
	if (ft_strequ(argv[0], "echo"))
		bi_echo(argv);
	else if (ft_strequ(argv[0], "cd"))
		bi_cd(argv);
	else if (ft_strequ(argv[0], "pwd"))
		bi_pwd();
	else if (ft_strequ(argv[0], "setenv"))
		bi_setenv(argv);
	else if (ft_strequ(argv[0], "unsetenv"))
		bi_unsetenv(argv, 0);
	else if (ft_strequ(argv[0], "env"))
		bi_env(argv);
	else
		other_commands(argv, commands, ptr);
	ft_free_tab((void**)argv);
}

void			run_commands(char **command, int i, char *ptr)
{
	char	**argv;
	char	**commands;

	ptr = ft_strtrim(*command);
	ft_strdel(command);
	if (!ptr[0] || !(commands = ft_strsplit(ptr, ';')))
	{
		ft_strdel(&ptr);
		return ;
	}
	while (commands[i])
	{
		if (!(argv = ft_split_whitespaces(commands[i++])))
			continue ;
		choose_commands(argv, commands, &ptr);
	}
	ft_free_tab((void**)commands);
	ft_strdel(&ptr);
}
