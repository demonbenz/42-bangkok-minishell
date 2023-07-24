/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 05:30:50 by schaisil          #+#    #+#             */
/*   Updated: 2022/06/13 18:43:54 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_str(char const *s)
{
	int	l;

	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}

// note: send in function as argument and apply it to each character of str
//       then allocate & create new string of that result, return the pointer
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		len;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = len_str(s);
	result = (char *) malloc((len + 1) * sizeof(char));
	if (result != NULL)
	{
		if (len == 0)
			result[0] = '\0';
		else
		{
			i = 0;
			while (s[i] != '\0')
			{
				result[i] = f(i, s[i]);
				i++;
			}
			result[i] = '\0';
		}
	}
	return (result);
}

// example of input function
// static char f42(unsigned int i, char s)
// {
// 	return (i != 4) ? s + 2 : s;
// }
