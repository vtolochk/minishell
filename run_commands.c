/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:41:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/23 12:41:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void choose_command(char **argv, t_env_lst *lst, char **ptr)
{
	if (ft_strequ(*ptr, "exit"))
	{
		free_list(&lst);
		ft_strdel(ptr);
		exit(OK);
	}
	if (ft_strequ(argv[0], "ls"))
		new_process("/bin/ls", argv);
	else if (ft_strequ(argv[0], "echo"))
		builtin_echo(argv);
//	else if (ft_strequ(argv[0], "cd"))
//		builtin_cd(argv);
//	else if (ft_strequ(argv[0], "setenv"))
//		builtin_setenv(argv, lst);
//	else if (ft_strequ(argv[0], "unsetenv"))
//		builtin_unsetenv(argv, lst);
//	else if (ft_strequ(argv[0], "env"))
//		builtin_env(argv, lst);
	else
		ft_printf("minishell: %s: command not found\n", argv[0]);
	ft_free_tab((void**)argv);
}

void run_commands(char **command, t_env_lst *list)
{
	int i;
	char *ptr;
	char **argv;
	char **commands;

	i = 0;
	ptr = ft_strtrim(*command);
	ft_strdel(command);
	if (!ptr[0] || !(commands = ft_strsplit(ptr, ';')))
	{
		ft_strdel(&ptr);
		return ;
	}
	while (commands[i])
	{
		if (!(argv = ft_split_whitespaces(commands[i])))
			break ;
		choose_command(argv, list, &ptr);
		i++;
	}
	ft_free_tab((void**)commands);
	ft_strdel(&ptr);
}