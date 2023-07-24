/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:50:52 by schaisil          #+#    #+#             */
/*   Updated: 2022/07/27 04:31:45 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	u_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*u_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*result;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = u_strlen(s1);
	len_s2 = u_strlen(s2);
	result = (char *) malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (result != NULL)
	{
		i = -1;
		while (++i < len_s1)
			result[i] = s1[i];
		while (i < len_s1 + len_s2)
		{
			result[i] = s2[i - len_s1];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}

// note: find out whether s contain '\n' character
//       return 1 (true), return 0 (false)
//       return 0, if s is NULL
int	has_endl(char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// note: count length of s until 1st encounter of '\n' or '\0'
//       counting include '\n' but not '\0'
//       return 0, if s is NULL
int	len_endl(const char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}
