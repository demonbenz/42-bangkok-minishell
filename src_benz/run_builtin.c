/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:32:04 by otangkab          #+#    #+#             */
/*   Updated: 2023/07/18 04:58:36 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../src/bi_cmds.h"

int	try_execute_child_buildin(t_exec *exec)
{
	if (exec->arg->cmd[0] == NULL)
		return (0);
	else if (ft_isequalstrn(exec->arg->cmd[0], "echo", 0))
		return (run_bcho(exec->arg->cmd), 1);
	else if (ft_isequalstrn(exec->arg->cmd[0], "pwd", 0))
		return (run_pwd(), 1);
	else if (ft_isequalstrn(exec->arg->cmd[0], "env", 0))
		return (run_env(exec->arg->cmd, exec->envp), 1);
	else if (ft_isequalstrn(exec->arg->cmd[0], "export", 0) && \
	exec->arg->cmd[1] == NULL)
		return (run_export_no_arg(exec), 1);
	return (0);
}
