/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:58:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/23 19:58:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print(char *str)
{
	while (*str)
	{
		if (*str != '\'' && *str != '\"')
			write(1, &(*str), 1);
		str++;
	}
}

int bi_echo(char **argv)
{
	int i;
	char new_line;

	i = 1;
	new_line = 1;
	if (ft_strequ(argv[i], "-n"))
	{
		new_line = 0;
		i++;
	}
	while (argv[i])
	{
		print(argv[i++]);
		write(1, " ", 1);
	}
	if (new_line)
		write(1, "\n", 1);
	return (OK);
}