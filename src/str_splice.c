/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_splice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:51:17 by schaisil          #+#    #+#             */
/*   Updated: 2023/05/30 15:20:11 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

char	*strdup_big(const char *s1, int bytes)
{
	int		len;
	char	*result;
	int		i;

	len = 0;
	while (s1[len] != '\0')
		len++;
	result = malloc((bytes) * sizeof(char));
	if (result != NULL)
	{
		ft_bzero(result, bytes);
		i = 0;
		while (i < len)
		{
			result[i] = s1[i];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}

// 	char *str = strdup("abc12345def");
//  note: assume proper input, handle 4 cases
//  front: 0 to 2
//  middle: 2 to 4
//  back: 3 to n
//  all: 0 to n
char	*str_splice(char *str, int start, int del_count)
{
	int		len;
	int		len_back;
	int		i;
	char	*result;

	result = ft_substr(str, start, del_count);
	len = ft_strlen(str);
	len_back = len - (start + del_count);
	i = 0;
	while (i < len_back)
	{
		str[start + i] = str[start + del_count + i];
		i++;
	}
	str[start + i] = '\0';
	return (result);
}
