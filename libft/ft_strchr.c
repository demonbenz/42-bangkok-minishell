/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:48:14 by schaisil          #+#    #+#             */
/*   Updated: 2022/06/12 05:07:54 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// note: search 'c' in str | return address of the 1st occurrence
//       return NULL if not found
//       comparison done by converted to a char
//       '\0' is consider as part of the string
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *) &s[i]);
		i++;
	}
	if (ch == '\0')
		return ((char *) &s[i]);
	else
		return (NULL);
}
