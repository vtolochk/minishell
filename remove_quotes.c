/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:26:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/30 21:18:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_quotes(char **str)
{
	int		i;
	int		j;
	int		quotes;
	char	*new_str;

	i = 0;
	j = 0;
	quotes = 0;
	if (!(*str))
		return ;
	while ((*str)[i])
	{
		if ((*str)[i] == 34 || (*str)[i] == 39)
			quotes++;
		i++;
	}
	if (!quotes)
		return ;
	new_str = ft_strnew((ft_strlen(*str) - quotes) + 1);
	i = -1;
	while ((*str)[++i])
		if (((*str)[i] != '\'' && (*str)[i] != '\"'))
			new_str[j++] = (*str)[i];
	ft_strdel(str);
	*str = new_str;
}
