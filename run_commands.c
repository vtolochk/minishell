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

void choose_command(char **argv, t_env_lst *lst)
{
	(void)lst;
	if (ft_strequ(argv[0], "echo"))
		bi_echo(argv);
//	else if (ft_strequ(argv[0], "cd"))
//		bi_cd(argv);
	else if (ft_strequ(argv[0], "setenv"))
		bi_setenv(argv, &lst);
	else if (ft_strequ(argv[0], "unsetenv"))
		bi_unsetenv(argv, &lst);
	else if (ft_strequ(argv[0], "env"))
		bi_env(argv, lst);
	else
	{
		if (ft_strequ(argv[0], "exit"))
			ft_printf("minishell: %s: command not found\n", argv[1]);
		else
			ft_printf("minishell: %s: command not found\n", argv[0]);
	}
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
		if (ft_strequ(ptr, "exit"))
		{
			ft_free_tab((void**)argv);
			ft_free_tab((void**)commands);
			free_list(&list);
			ft_strdel(&ptr);
			exit(OK);
		}
		choose_command(argv, list);
		i++;
	}
	ft_free_tab((void**)commands);
	ft_strdel(&ptr);
}