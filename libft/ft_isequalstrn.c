/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isequalstrn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 07:03:02 by schaisil          #+#    #+#             */
/*   Updated: 2023/03/07 13:58:24 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// note: support NULL and empty_str input
//       when both str is not NULL -> compare logic
//       comparing bytes stop at first encounter of diffrent byte value or '\0'
// return: 1 (equal), 0 (not_equal)

// n = 0 (default): compare all bytes from both str
// s1 = "abc", s2 = "abc123" | n = 0 (return 0),
// n = 3 (return 1), n = 4+ (return 0)
// stop compare after encounter any '\0'
int	ft_isequalstrn(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (s1 == s2)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (!(s1[i] == '\0' && s2[i] == '\0'))
	{
		if (n > 0 && i >= n)
			break ;
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
