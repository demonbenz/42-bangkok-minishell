/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:15:33 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/24 21:52:19 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int	get_last_zq_index(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr("$'\"", str[i]) != NULL)
			break ;
		i++;
	}
	return (i);
}

char	*zq_expand(char *str, int last_c_index, char **envs)
{
	if (str || last_c_index || envs)
	{
	}
	return (NULL);
}
