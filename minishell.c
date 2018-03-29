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

char **remove_tild(char **argv)
{
	int i;
	int j;
	char **new;
	char *find;
	char *temp;

	j = 0;
	i = array_len(argv);
	new = new_array(i);
	while (i-- > 0)
	{
		new[j] = ft_strdup(argv[j]);
		j++;
	}
	i = 0;
	while (new[i])
	{
		find = ft_strchr(new[i], '~');
		if (find)
		{
			temp = get_value_by_name("HOME");
			new[i] = ft_strjoin(++temp, ++find);
		}
		i++;
	}
	return (new);
}

void new_process(char *process, char **argv)
{
	char **new_argv;
	pid_t pid;
	char **env_vars;

	env_vars = list_to_array();
	pid = fork();
	new_argv = remove_tild(argv);
	if (pid == 0)
	{
		execve(process, new_argv, env_vars);
		ft_strdel(&process);
		ft_free_tab((void **)env_vars);
		ft_free_tab((void **)new_argv);
		free_list();
		exit(0);
	}
	wait(&pid);
	ft_strdel(&process);
	ft_free_tab((void **)new_argv);
	ft_free_tab((void **)env_vars);
}

void print_promt(void)
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
		ft_printf("%magenta%[%s]%eoc%%green%[%s]%eoc%%yellow%$>%eoc%\n", ++log_name, pwd);
		ft_strdel(&pwd);
	}
	else
		ft_printf("%magenta%[%s]%eoc%%green%[%s]%eoc%%yellow%$>%eoc%\n", ++log_name, pwd);
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
