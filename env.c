/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:16:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/30 21:27:20 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		bi_env(char **argv)
{
	if (!argv[1])
		print_list();
	else
	{
		write(2, "Usage: env\n", 12);
		return (FAIL);
	}
	return (OK);
}
