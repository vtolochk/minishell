/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:28:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/30 21:21:59 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_process(char *process, char **argv)
{
	pid_t	pid;
	char	**new_argv;
	char	**env_vars;

	env_vars = list_to_array();
	pid = fork();
	new_argv = remove_tild(argv, 0, 0);
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
