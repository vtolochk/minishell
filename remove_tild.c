/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_tild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:59:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/30 15:59:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void tild_helper(char **argv, char **new)
{
	int i;
	int j;
	char *find;

	i = 0;
	j = 0;
	while (new[i])
	{
		find = ft_strchr(new[i], '$');
		if (find)
		{
			while (argv[j])
			{
				find = ft_strchr(argv[j], '$');
				if (find)
				{
					new[i] = remove_dollar(argv[j]);
					break ;
				}
				j++;
			}
		}
		i++;
	}
}

char **remove_tild(char **argv, int j)
{
	int i;
	char **new;
	char *find;
	char *temp;

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
	tild_helper(argv, new);
	return (new);
}