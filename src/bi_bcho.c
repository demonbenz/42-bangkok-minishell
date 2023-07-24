/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_bcho.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 06:26:41 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/01 07:41:03 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bi_cmds.h"

int	run_bcho(char **cmd)
{
	int	i;

	if (cmd[1] == NULL)
		return (ft_printf("\n"), 1);
	if (ft_isequalstrn(cmd[1], "-n", 0) && cmd[2] == NULL)
		return (1);
	if (ft_isequalstrn(cmd[1], "-n", 0))
		i = 2;
	else
		i = 1;
	bcho_with_text(cmd, i);
	if (!ft_isequalstrn(cmd[1], "-n", 0))
		ft_printf("\n");
	return (1);
}

void	bcho_with_text(char **cmd, int first)
{
	int	i;

	i = first;
	while (cmd[i] != NULL)
	{
		if (i == first)
			ft_printf("%s", cmd[i]);
		else
			ft_printf(" %s", cmd[i]);
		i++;
	}
}
