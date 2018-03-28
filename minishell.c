/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 20:22:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/23 11:14:32 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void new_process(char *process, char **argv)
{
	pid_t pid;
	char **env_vars;

	env_vars = list_to_array();
	pid = fork();
	if (pid == 0)
	{
		execve(process, argv, env_vars);
		ft_free_tab((void **)env_vars);
		exit(0);
	}
	wait(&pid);
	ft_free_tab((void **)env_vars);
}

void print_promt(void)
{
	char *pwd;
	char *log_name;

	pwd = get_value_by_name("PWD");
	log_name = get_value_by_name("LOGNAME");
	ft_printf("%magenta%[%s]%eoc%%green%[%s]%eoc%%yellow%$>%eoc%\n", ++log_name, ++pwd);
}

int     main(int argc, char **argv, char **envp)
{
	char *line;
	(void)argc;
	(void)argv;

	g_vars = copy_env(envp);
	while (1)
	{
		print_promt();
		get_next_line(0, &line);
		if (!line)
			write(1, "\n", 1);
		else
			run_commands(&line);
	}
	return (OK);
}
