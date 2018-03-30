/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:58:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/30 21:28:13 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		echo_print(char *str)
{
	char *temp;
	char *value;
	char *without_quotes;

	without_quotes = ft_strdup(str);
	remove_quotes(&without_quotes);
	temp = without_quotes;
	while (*without_quotes)
	{
		if (*without_quotes == '$')
		{
			without_quotes++;
			if ((value = get_value_by_name(without_quotes)))
			{
				ft_printf("%s", ++value);
				ft_strdel(&temp);
				return ;
			}
			else
				without_quotes--;
		}
		write(1, without_quotes, 1);
		without_quotes++;
	}
	ft_strdel(&temp);
}

int				bi_echo(char **argv)
{
	int		i;
	char	new_line;

	i = 1;
	new_line = 1;
	if (ft_strequ(argv[i], "-n"))
	{
		new_line = 0;
		i++;
	}
	while (argv[i])
	{
		echo_print(argv[i]);
		if (argv[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (new_line)
		write(1, "\n", 1);
	else
	{
		write(1, "\e[7m", 5);
		write(1, "%", 1);
	}
	return (OK);
}
