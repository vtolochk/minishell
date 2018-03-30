/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:47:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/30 21:47:33 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		words_num(char *str)
{
	int words;

	words = 0;
	while (*str)
	{
		while (*str && WHITESPACE)
			str++;
		if (!(*str))
			break ;
		words++;
		while (*str && !(WHITESPACE))
			str++;
		if (!(*str))
			break ;
	}
	return (words);
}

int		fill_array(char **array, char *str, int words)
{
	int		i;
	char	*ptr;

	i = 0;
	while (words-- > 0)
	{
		while (*str && WHITESPACE)
			str++;
		ptr = str;
		while (*str && !(WHITESPACE))
			str++;
		if (!(array[i++] = ft_strsub(ptr, 0, str - ptr)))
			return (1);
	}
	return (0);
}

char	**ft_split_whitespaces(char *str)
{
	int		words;
	char	**array;

	if (!str)
		return (NULL);
	words = words_num(str);
	if (words == 0)
	{
		array = NULL;
		return (array);
	}
	if (!(array = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	array[words] = NULL;
	if (fill_array(array, str, words) == 1)
		return (NULL);
	return (array);
}
