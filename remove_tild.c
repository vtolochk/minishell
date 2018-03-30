/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_tild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:59:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/30 21:17:30 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		tild_helper(char **argv, char **new, int i)
{
	int		j;
	char	*find;

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
					find = new[i];
					new[i] = remove_dollar(argv[j]);
					ft_strdel(&find);
					break ;
				}
				j++;
			}
		}
		i++;
	}
}

char			**remove_tild(char **argv, int j, int i)
{
	char **new;
	char *find;
	char *temp[2];

	i = array_len(argv);
	new = new_array(i);
	while (i-- > 0)
	{
		new[j] = ft_strdup(argv[j]);
		j++;
	}
	i = -1;
	while (new[++i])
	{
		find = ft_strchr(new[i], '~');
		if (find)
		{
			temp[0] = get_value_by_name("HOME");
			temp[1] = new[i];
			new[i] = ft_strjoin(++(temp[0]), ++find);
			ft_strdel(&(temp[1]));
		}
	}
	tild_helper(argv, new, 0);
	return (new);
}
