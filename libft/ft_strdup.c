/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:07:26 by schaisil          #+#    #+#             */
/*   Updated: 2022/06/13 13:08:25 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// note: allocated memory for a copy of s1, does the copy, and return a pointer
char	*ft_strdup(const char *s1)
{
	int		len;
	char	*result;
	int		i;

	len = 0;
	while (s1[len] != '\0')
		len++;
	result = malloc((len + 1) * sizeof(char));
	if (result != NULL)
	{
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
