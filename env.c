/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:16:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/24 20:16:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int bi_env(char **argv, t_env_lst *list)
{
	if (!argv[1])
		print_list(list);
	else
	{
		write(2, "Usage: env\n", 12);
		return (FAIL);
	}
	return (OK);
}
