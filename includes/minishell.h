/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 20:09:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/22 20:16:44 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/includes/libft.h"
#include <sys/param.h>
#include <sys/stat.h>
#include <dirent.h>

#define OK 0
#define FAIL 1

typedef struct s_env_lst
{
	char *name;
	char *value;
	struct s_env_lst	*next;
}               t_env_lst;

t_env_lst *g_vars;

void run_commands(char **command, int i, char *ptr);
char **remove_tild(char **argv, int j);
char *remove_dollar(char *argv);
char **new_array(int size);
int array_len(char **array);
void print_list(void);
void change_node_value(char *name, char *new_value);
t_env_lst *new_node(void);
t_env_lst *copy_env(char **envp);
void list_push_back(t_env_lst *new_node);
char *get_value_by_name(char *name);
int check_dir(DIR *dir_ptr, char *name);
char *find_a_file(char *dir, char *name, int i);
int execute_files(char **argv);
void free_list(void);
void new_process(char *process, char **argv);
char **list_to_array(void);
int list_len(t_env_lst *lst);
int remove_node(char *name);
void remove_quotes(char **str);
int count_sign(char *str, char sign);
int bi_echo(char **argv);
int bi_pwd(void);
int bi_env(char **argv);
int bi_setenv(char **argv);
int bi_unsetenv(char **argv);
int bi_cd(char **argv);

#endif
