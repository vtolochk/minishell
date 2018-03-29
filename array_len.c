/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:41:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/29 18:41:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int array_len(char **array)
{
	int size;

	size = 0;
	if (!array || !array[size])
		return (size);
	while (array[size])
		size++;
	return (size);
}