/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:33:44 by schaisil          #+#    #+#             */
/*   Updated: 2022/06/12 05:36:23 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// note: identical as ft_strchr, except return address of the last occurrence
//       perform backward search instead
//       beware "4321\0abcd", in this case, strlen only count as 4
//       strrchr("4321\0abcd", '\0') -> &s[4]
//       strrchr("4321abcd", '\0') -> &s[8]
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (char) c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
