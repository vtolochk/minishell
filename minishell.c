/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 20:22:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/04/18 20:30:58 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		clean_screen(void)
{
	char esc;

	esc = 27;
	write(1, &esc, 1);
	write(1, "[2J", 3);
	write(1, &esc, 1);
	write(1, "[1;1H", 5);
}

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
		ft_printf("%magenta%[%s]%eoc%%green%[%s]%eoc%$>\n", ++log_name, pwd);
		ft_strdel(&pwd);
	}
	else
		ft_printf("%magenta%[%s]%eoc%%green%[%s]%eoc%$>\n", ++log_name, pwd);
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
	clean_screen();
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
