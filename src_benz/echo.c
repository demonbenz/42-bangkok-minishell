/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <otangkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:14:10 by otangkab          #+#    #+#             */
/*   Updated: 2023/07/10 22:21:52 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	echo_with_text(char **cmd, int first)
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

int	run_echo(t_exec *exec)
{
	int	i;

	if (exec->arg->cmd[1] == NULL)
		return (ft_printf("\n"), 1);
	if (ft_isequalstrn(exec->arg->cmd[1], "-n", 0) && exec->arg->cmd[2] == NULL)
		return (1);
	if (ft_isequalstrn(exec->arg->cmd[1], "-n", 0))
		i = 2;
	else
		i = 1;
	echo_with_text(exec->arg->cmd, i);
	if (!ft_isequalstrn(exec->arg->cmd[1], "-n", 0))
		ft_printf("\n");
	return (0);
}
