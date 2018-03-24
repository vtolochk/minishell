/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:16:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/24 20:16:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int builtin_env(char **argv, t_env_lst *list)
{
	(void)argv;
	print_list(list);
	return (0);
}
