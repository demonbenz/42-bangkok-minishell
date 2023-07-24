/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:27:21 by otangkab          #+#    #+#             */
/*   Updated: 2023/07/22 16:49:53 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	run_exit(t_exec *exec)
{
	if (exec->arg->cmd[1] != NULL)
	{
		if (is_str_number(exec->arg->cmd[1]))
		{
			if (exec->arg->cmd[2] != NULL)
			{
				*exec->cmd_exit_num = 1;
				printf("bash: exit: too many arguments\n");
				return ;
			}
			*exec->app_exit_num = (ft_atoi(exec->arg->cmd[1]) % 256);
		}
		else
		{
			printf("bash: exit: %s numeric argument required\n", \
				exec->arg->cmd[1]);
			*exec->app_exit_num = 255;
		}
	}
	else
		*exec->app_exit_num = 0;
	*exec->exit = 1;
}
