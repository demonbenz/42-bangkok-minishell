/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 02:09:36 by schaisil          #+#    #+#             */
/*   Updated: 2022/06/13 08:05:12 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// note: append up to dstsize - strlen(dst) - 1 characters from src to dst
//       ie. strlen(dst) = 3, dstsize = 8 -> can append up to 4 char -> '\0'
//       guarantee NULL-termination if there is room
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	max_append;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize == 0 || dstsize <= len_dst)
		return (dstsize + len_src);
	max_append = dstsize - len_dst - 1;
	i = 0;
	while (src[i] != '\0' && i < max_append)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
