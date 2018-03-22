/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 20:22:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/22 20:22:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     main(int argc, char **argv, char **envp)
{
	char *line;
	argc--;
	argv--;
	envp--;

	ft_printf("$>");
	while (1)
	{
		get_next_line(0, &line);
		if (ft_strcmp(line, "exit") == 0)
			exit(0);
	}
	return (0);
}
