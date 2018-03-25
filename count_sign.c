/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 21:02:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/25 21:02:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int count_sign(char *str, char sign)
{
	int sum;

	sum = 0;
	if (!str || !sign)
		return (0);
	while (*str)
	{
		if (*str == sign)
			sum++;
		str++;
	}
	return (sum);
}