/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 05:13:34 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/16 15:09:52 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_delimeter(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*construct_str(int len, int fd_len, int bd_len, char const *s1)
{
	char	*result;
	int		i;
	int		new_len;

	if (fd_len == len)
	{
		result = (char *) malloc(1 * sizeof(char));
		if (result != NULL)
			result[0] = '\0';
		return (result);
	}
	new_len = len - fd_len - bd_len;
	result = (char *) malloc((new_len + 1) * sizeof(char));
	if (result != NULL)
	{
		i = 0;
		while (i < new_len)
		{
			result[i] = s1[fd_len + i];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}

// note: allocate and return a copy of s1 with the character in 'set'
//       removed from the beginning and the end of string
//       return the trimmed string, or NULL if allocation fail
char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		fd_len;
	int		bd_len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = 0;
	fd_len = 0;
	bd_len = 0;
	while (s1[len] != '\0')
		len++;
	if (len > 0)
	{
		while (s1[fd_len] != '\0' && is_delimeter(s1[fd_len], set))
			fd_len++;
		while (bd_len < len && is_delimeter(s1[len - bd_len - 1], set))
			bd_len++;
	}
	return (construct_str(len, fd_len, bd_len, s1));
}
