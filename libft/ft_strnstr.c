/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 03:43:07 by schaisil          #+#    #+#             */
/*   Updated: 2022/06/12 07:53:51 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// note: search needle_str in haystack_str
//       return address of the 1st occurrence
//       read up to len bytes begin at &haystack[0], return NULL if not found
//       return haystack_str if needle_str is empty
//       character tha appear after a '\0' character are not searched
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *) haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *) &haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
