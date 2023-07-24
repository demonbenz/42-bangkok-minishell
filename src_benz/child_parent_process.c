/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_parent_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <otangkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:10:06 by otangkab          #+#    #+#             */
/*   Updated: 2023/07/24 14:32:49 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../src/bi_cmds.h"

void	parent_wait_command(t_exec *exec)
{
	int	exit_status;
	int	i;

	if (exec->arg->outfile_sym[0] != NULL || exec->arg->append_sym[0] != NULL \
	|| exec->arg->infile_sym[0] != NULL || exec->arg->heredoc_sym[0] != NULL)
	{
		waitpid(exec->pid, &exit_status, 0);
		*exec->cmd_exit_num = WEXITSTATUS(exit_status);
	}
	exec->all_pid[exec->index] = exec->pid;
	if ((exec->index < (*exec->total_cmds - 1)) && (*exec->total_cmds > 1))
		dup2(exec->fd[0], 0);
	else
	{
		i = 0;
		while (i < *exec->total_cmds)
		{
			waitpid(exec->all_pid[i], &exit_status, 0);
			*exec->cmd_exit_num = WEXITSTATUS(exit_status);
			i++;
		}
		dup2(exec->shell_input, 0);
	}
	close(exec->fd[1]);
	close(exec->fd[0]);
}

void	child_execution_command(t_exec *exec)
{
	if (redirect_input(exec) < 0)
		exit(1);
	dup_input(exec->fd);
	if (redirect_dup_output(exec) < 0)
		exit(1);
	if (try_execute_child_buildin(exec))
		exit(0);
	else
		exit(child_execution_step(exec));
}
// exit(0);
