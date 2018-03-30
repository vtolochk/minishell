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

int check_dir(DIR *dir_ptr, char *name)
{
	struct dirent *dir_info;

	if (dir_ptr)
	{
		while ((dir_info = readdir(dir_ptr)))
		{
			if (ft_strequ(dir_info->d_name, name))
			{
				closedir(dir_ptr);
				return (OK);
			}
		}
		closedir(dir_ptr);
	}
	return (FAIL);
}

char *create_full_path(char *dir, char *name)
{
	char *temp;
	char *full_path;

	full_path = ft_strjoin(dir, "/");
	temp = full_path;
	full_path = ft_strjoin(full_path, name);
	ft_strdel(&temp);
	return (full_path);
}

char *find_a_file(char *dir, char *name, int i)
{
	char *path;
	char **path_names;
	char *full_path;
	DIR *dir_ptr;

	if (dir)
	{
		if (!(dir_ptr = opendir(dir)))
			return (NULL);
//		if ((check_dir(dir_ptr, name) == OK))
//			return (create_full_path(dir, name));
//		else
//			return (NULL);
		return (check_dir(dir_ptr, name) == OK ? create_full_path(dir, name) : NULL);
	}
	if (!(path = get_value_by_name("PATH")) || !(path_names = ft_strsplit(++path, ':')))
		return (NULL);
	while (path_names[i])
	{
		dir_ptr = opendir(path_names[i]);
		if (check_dir(dir_ptr, name) == OK)
		{
			full_path = create_full_path(path_names[i], name);
			ft_free_tab((void **)path_names);
			return (full_path);
		}
		i++;
	}
	ft_free_tab((void **)path_names);
	return (NULL);
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
		*dir = NULL;
		*file = ft_strdup(argv[0]);
	}
}

int execute_files(char **argv)
{
	int ret;
	char *dir;
	char *file;
	char *full_path;

	ret = FAIL;
	get_dir_and_file(argv, &dir, &file);
	if ((full_path = find_a_file(dir, file, 0)))
	{
		if (access(full_path, X_OK) == -1)
			ft_printf("minishell: permission denied: %s\n", file);
		else
			new_process(full_path, argv);
		ret = OK;
	}
	else if (ft_strchr(argv[0], '/'))
	{
		ft_printf("minishell: no such file or directory: %s\n", file);
		ret = OK;
	}
	ft_strdel(&dir);
	ft_strdel(&file);
	return (ret);
}
