/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 04:19:57 by schaisil          #+#    #+#             */
/*   Updated: 2022/07/21 14:43:00 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*result;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
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
