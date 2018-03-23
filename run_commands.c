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

void run_commands(char **command, t_envlst *list)
{
	char *ptr;

	ptr = ft_strtrim(*command);
	ft_strdel(command);
	if (!ptr[0])
	{
		ft_strdel(&ptr);
		return ;
	}
	else if (ft_strcmp(ptr, "exit") == 0)
	{
		free_list(&list);
		exit(OK);
	}
	else if (ft_strcmp(ptr, "env") == 0)
		print_list(list);
	else
		ft_printf("minishell: %s: command not found\n", ptr);
	ft_strdel(&ptr);
}