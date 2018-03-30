/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 20:22:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/30 21:23:16 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		print_prompt(void)
{
	char *pwd;
	char *find;
	char *home;
	char *log_name;

	pwd = get_value_by_name("PWD");
	home = get_value_by_name("HOME");
	log_name = get_value_by_name("LOGNAME");
	if ((find = ft_strstr(++pwd, ++home)))
	{
		pwd = ft_strjoin("~", find + ft_strlen(home));
		ft_printf("%magenta%[%s]%eoc%%green%[%s]%eoc%\n", ++log_name, pwd);
		write(0, "$> ", 3);
		ft_strdel(&pwd);
	}
	else
	{
		ft_printf("%magenta%[%s]%eoc%%green%[%s]%eoc%\n", ++log_name, pwd);
		write(0, "$> ", 3);
	}
}

static void		print_signal(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	print_prompt();
}

int				main(int argc, char **argv, char **envp)
{
	char *line;

	(void)argc;
	(void)argv;
	g_vars = copy_env(envp);
	while (1)
	{
		signal(SIGINT, print_signal);
		print_prompt();
		get_next_line(0, &line);
		if (!line)
			write(1, "\n", 1);
		else
			run_commands(&line, 0, 0);
	}
	return (OK);
}
