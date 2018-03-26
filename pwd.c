/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:15:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/26 16:15:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int bi_pwd(void)
{
	char *value;

	value = get_value_by_name("PWD");
	if (!value)
		return (FAIL);
	ft_printf("%s\n", ++value);
	return (OK);
}