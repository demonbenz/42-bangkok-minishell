/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:08:15 by schaisil          #+#    #+#             */
/*   Updated: 2022/06/12 17:21:48 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// note: compare s1 vs s2 (byte by byte)
//       return the difference treated as an unsigned char, '\200' > '\0'
//       read up to n characters
//       will compare character that appear after a '\0' character
//       comparison done by converted to an unsigned char
//       some libc only return (-1, 0, 1)
//       zero-length strings are always identical
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
