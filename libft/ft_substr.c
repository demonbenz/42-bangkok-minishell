/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:47:42 by schaisil          #+#    #+#             */
/*   Updated: 2022/06/13 15:42:55 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	filter_len(size_t src_len, unsigned int start, size_t len)
{
	if (len > src_len - start)
		return (src_len - start);
	else
		return (len);
}

static char	*construct_str(size_t src_len, unsigned int start, size_t len,
	char const *s)
{
	char	*result;
	size_t	i;

	if (s[0] == '\0' || len == 0 || start >= src_len)
	{
		result = (char *) malloc(1 * sizeof(char));
		if (result != NULL)
			result[0] = '\0';
	}
	else
	{
		len = filter_len(src_len, start, len);
		result = (char *) malloc((len + 1) * sizeof(char));
		if (result != NULL)
		{
			i = 0;
			while (i < len)
			{
				result[i] = s[start + i];
				i++;
			}
			result[i] = '\0';
		}
	}
	return (result);
}

// note: allocate and return a substring from string 's'
//       the substring begins at index 'start', and up to max size of 'len'
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	src_len;

	if (s == NULL)
		return (NULL);
	src_len = 0;
	while (s[src_len] != '\0')
		src_len++;
	return (construct_str(src_len, start, len, s));
}
