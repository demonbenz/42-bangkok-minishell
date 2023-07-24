/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:55:19 by schaisil          #+#    #+#             */
/*   Updated: 2022/06/13 09:53:01 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// note: copy n bytes from src to dst,
//       if dst and src overlap, the copy is done in non-destructive manner
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == NULL && src == NULL && len > 0)
		return (dst);
	i = 0;
	if (dst > src)
	{
		while (i < len)
		{
			((unsigned char *) dst)[len - i - 1] = ((unsigned char *) src)
			[len - i - 1];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
			i++;
		}
	}
	return (dst);
}

// char src[8] = {'A', 'B', 'C', 'D', 'E', '0', '#', '\0'}; | address: 0x0005
//       src+2 =           {'C', 'D', 'E', '0', '#', '\0'}; | address: 0x0007
// memcpy(src+2, src, 5) - undefine
// memmove(src+2, src, 5) - guarantee non-destructive by reverse copy
// memcpy(src, src+2, 5) - undefine
// memmove(src, src+2, 5) - guarantee non-destructive by forward copy
// memcpy(dst, src, 5) - no overlap case, forward/reverse both ok
// memmove(dst, src, 5) - no overlap case, forward/reverse both ok
// ----------------------------------------------------------------------------
// memmove(src+2, src, 5) - cannot forward copy because on 1st byte copy,
//                          src: will change from "ABCDE0#" to "ABADE0#"
// memmove(src, src+2, 5) - cannot reverse copy because on 1st byte copy,
//                          src+2: will change from "CDE0#" to "CD#0#"
//
// Guacamolle's clib behavior
// --------------------------
// [dst], [src], [size]
// s1, s2, 0 - do nothing
// NULL, s2, 0 - do nothing
// s1, NULL, 0 - do nothing
// NULL, NULL, 0 - do nothing
//
// s1, s2, 1 - normal copy
// s1, NULL, 1 - segmentation fault
// NULL, s2, 1 - segmentation fault
// NULL, NULL, 1 - do nothing
// --------------------------
