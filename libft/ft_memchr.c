/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:46:41 by schaisil          #+#    #+#             */
/*   Updated: 2022/06/12 07:38:21 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// note: search 'c' in str | return address of the 1st occurrence
//       read up to n bytes begin at &s[0], return NULL if not found
//       comparison done by converted to an unsigned char
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ucs;

	ucs = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (ucs[i] == (unsigned char) c)
			return ((void *) &ucs[i]);
		i++;
	}
	return (NULL);
}
