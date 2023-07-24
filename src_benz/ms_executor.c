/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:57:07 by otangkab          #+#    #+#             */
/*   Updated: 2023/07/24 22:33:48 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "exec.h"
#include "../src/bi_cmds.h"

void	set_val(int *var, int val)
{
	*var = val;
}

int	try_execute_quiet_buildin(t_exec *exec)
{
	if (ft_isequalstrn(exec->arg->cmd[0], "exit", 0))
		return (run_exit(exec), 0);
	if (ft_isequalstrn(exec->arg->cmd[0], "cd", 0))
		return (run_cd(exec), 0, 0);
	if (ft_isequalstrn(exec->arg->cmd[0], "unset", 0))
		return (run_unset(exec), set_val(exec->cmd_exit_num, 0), 0);
	if (ft_isequalstrn(exec->arg->cmd[0], "export", 0) && \
	exec->arg->cmd[1] != NULL)
		return (run_export_with_arg(exec), 0);
	return (1);
}

int	run_single_command(t_exec *exec, t_info *info)
{
	if (try_execute_quiet_buildin(exec) == 0)
		return (0);
	if (pipe(exec->fd) < 0)
		return (-1);
	exec->pid = fork();
	if (exec->pid < 0)
		return (-1);
	if (exec->pid == 0)
	{
		info->sa_i.sa_handler = handle_sigint_child;
		sigaction(SIGINT, &info->sa_i, NULL);
		child_execution_command(exec);
	}
	else if (exec->pid > 0)
	{
		parent_wait_command(exec);
		return (1);
	}
	return (100);
}

void	init_exec(t_exec *exec, t_info *info)
{
	exec->index = -1;
	exec->shell_input = dup(0);
	exec->exit = &(info->exit);
	exec->app_exit_num = &(info->app_exit_num);
	exec->cmd_exit_num = &(info->cmd_exit_num);
	exec->sa_i = &(info->sa_i);
	exec->sa_q = &(info->sa_q);
	exec->total_cmds = &(info->total_cmds);
	exec->all_pid = malloc(sizeof(int) * info->total_cmds);
	exec->envp = info->envs;
	exec->info_ptr = info;
}
// ft_printf("cmd_num: %d\n", *exec->total_cmds);
// ft_printf("total_cmd: %d\n", info->total_cmds);
// ft_printf("size: %d\n", sizeof(int) * *exec->total_cmds);

int	ms_executor(t_list *cmds, t_info *info)
{
	t_exec	exec;

	init_exec(&exec, info);
	set_signal(info, IGNORE_SIGINT_PARENT);
	while (cmds != NULL)
	{
		exec.arg = (t_cmd *)cmds->content;
		exec.index++;
		if (run_single_command(&exec, info) < 0)
		{
			perror("single command error\n");
			return (1);
		}
		if (stat(TMP_FILE, &exec.tmp_file_info) == 0)
			unlink(TMP_FILE);
		cmds = cmds->next;
	}
	free(exec.all_pid);
	set_signal(info, HANDLE_SIGINT_PARENT);
	return (0);
}
	// return (*exec.cmd_exit_num);
