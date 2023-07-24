/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:19:12 by schaisil          #+#    #+#             */
/*   Updated: 2023/05/08 12:08:18 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_empty_input(char *str)
{
	int	i;

	i = 0;
	while (is_whitespace(str[i]))
		i++;
	return (str[i] == '\0');
}

int	is_whitespace(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	is_opt(char *str)
{
	return (ft_isequalstrn(str, "<", 0) || ft_isequalstrn(str, ">", 0) || \
			ft_isequalstrn(str, "<<", 0) || ft_isequalstrn(str, ">>", 0) || \
			ft_isequalstrn(str, "|", 0));
}
