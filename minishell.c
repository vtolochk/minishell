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
	pid = fork();
	if (pid == 0)
	{
		execv(process, argv);
		exit(0);
	}
	wait(&pid);
}

void print_promt(void)
{
	char *pwd;

	pwd = get_value_by_name("PWD");
	pwd++;
	write(0, "[", 1);
	write(0, pwd, ft_strlen((pwd)));
	write(0, "]", 1);
	write(0, " $> ", 4);
}

int     main(int argc, char **argv, char **envp)
{
	char *line;
	(void)argc;
	(void)argv;

	vars = copy_env(envp);
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
