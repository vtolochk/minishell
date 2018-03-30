/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:39:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/30 21:22:27 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**new_array(int size)
{
	int		i;
	char	**array;

	i = 0;
	if (size <= 0)
		return (NULL);
	if (!(array = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i <= size)
		array[i++] = NULL;
	return (array);
}
