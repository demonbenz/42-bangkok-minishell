/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:25:46 by schaisil          #+#    #+#             */
/*   Updated: 2023/03/20 17:26:16 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_str_number(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	if (!ft_isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return (0);
	if ((str[0] == '+' || str[0] == '-') && str[1] == '\0')
		return (0);
	i = 1;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
