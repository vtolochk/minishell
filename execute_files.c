/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:30:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/27 16:30:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int find_a_file(DIR *ptr, char *name)
{
	struct dirent *dir_info;

	while ((dir_info = readdir(ptr)))
	{
		if (ft_strequ(dir_info->d_name, name))
			return (OK);
	}
	return (FAIL);
}

void get_dir_and_file(char **argv, char **dir, char **file)
{
	char *find;

	find = ft_strrchr(argv[0], '/');
	if (find)
	{
		*dir = ft_strsub(argv[0], 0, find - argv[0]);
		*file = ft_strsub(argv[0], ft_strlen(*dir) + 1, ft_strlen(argv[0]) - ft_strlen(*dir));
	}
	else
	{
		*dir = get_value_by_name("PWD");
		*dir = ft_strdup(++(*dir));
		*file = ft_strdup(argv[0]);
	}
}

int execute_files(char **argv)
{
	int ret;
	char *dir;
	char *file;
	DIR *dir_ptr;

	ret = FAIL;
	get_dir_and_file(argv, &dir, &file);
	dir_ptr = opendir(dir);
	if (dir_ptr)
	{
		if (find_a_file(dir_ptr, file) == OK)
		{
			if (ft_strequ(argv[0], file))
				ret = FAIL;
			else if (access(argv[0], X_OK) == -1)
			{
				ft_printf("minishell: permission denied: %s\n", file);
				ret = OK;
			}
			else
			{
				new_process(argv[0], argv);
				ret = OK;
			}
		}
		else if (ft_strchr(argv[0], '/'))
		{
			ft_printf("minishell: no such file or directory: %s\n", file);
			ret = OK;
		}
	}
	ft_strdel(&dir);
	ft_strdel(&file);
	return (ret);
}
