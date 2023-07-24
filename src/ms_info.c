/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:45:47 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/23 17:08:29 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	free_info(t_info *info)
{
	free_split(info->envs);
}

void	free_split(char **strs)
{
	int	i;

	if (strs == NULL)
		return ;
	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	print_welcome_text(void)
{
	ft_printf("\033[1;32m __  __   _  _   ___ _        _ _ \n" \
	"|  \\/  (.) \\| (.) __| |_  ___| | |\n" \
	"| |\\/| | | .` | \\__ \\ ' \\/ -_) | |\n" \
	"|_|  |_|_|_|\\_|_|___/_||_\\___|_|_|\033[0m\n" \
	"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" \
	"~* \033[1;37mv1.0: created by Benz & Card\033[0m *~\n" \
	"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
