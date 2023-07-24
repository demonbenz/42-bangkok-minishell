/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_execution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:31:22 by otangkab          #+#    #+#             */
/*   Updated: 2023/07/24 22:38:26 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../src/minishell.h"

void	open_quit_signal_on_valid_cmd(t_exec *exec)
{
	if (ft_isequalstrn(exec->arg->cmd[0], "cat", 0) || \
		ft_isequalstrn(exec->arg->cmd[0], "/bin/cat", 0) || \
		(ft_isequalstrn(exec->arg->cmd[0], "grep", 0) && \
		exec->arg->cmd[1] != NULL) || \
		(ft_isequalstrn(exec->arg->cmd[0], "/usr/bin/grep", 0) && \
		exec->arg->cmd[1] != NULL) || \
		(ft_isequalstrn(exec->arg->cmd[0], "awk", 0) && \
		exec->arg->cmd[1] != NULL) || \
		(ft_isequalstrn(exec->arg->cmd[0], "/usr/bin/awk", 0) && \
		exec->arg->cmd[1] != NULL) || \
		(ft_isequalstrn(exec->arg->cmd[0], "wc", 0) && \
		exec->arg->cmd[1] == NULL) || \
		(ft_isequalstrn(exec->arg->cmd[0], "/usr/bin/wc", 0) && \
		exec->arg->cmd[1] == NULL))
	{
		exec->sa_q->sa_handler = handle_quit;
		sigaction(SIGQUIT, exec->sa_q, NULL);
	}
}

int	child_execution_step(t_exec *exec)
{
	if (exec->arg->cmd[0] == NULL)
		return (0);
	open_quit_signal_on_valid_cmd(exec);
	if (access(exec->arg->cmd[0], F_OK | R_OK | X_OK) == 0)
		return (simple_execution(exec));
	else
		return (join_path_then_execution(exec));
}

int	simple_execution(t_exec *exec)
{
	int	ret;

	ret = execve(exec->arg->cmd[0], exec->arg->cmd, exec->envp);
	if (ret < 0)
	{
		if (ft_isequalstrn(exec->arg->cmd[0], ".", 0))
			return (ft_printf("bash: .: filename argument required\n\
.: usage: . filename [arguments]\n"), 2);
		else if (ft_isequalstrn(exec->arg->cmd[0], "/", 0))
			return (ft_printf("bash: /: is a directory\n"), 126);
		else
			return (ft_printf("*bash: %s: command not found\n", \
			exec->arg->cmd[0]), 127);
	}
	return (0);
}

int	join_path_then_execution(t_exec *exec)
{
	int		ret;
	char	*tmp_cmd;

	tmp_cmd = exec->arg->cmd[0];
	exec->arg->cmd[0] = check_path(tmp_cmd, exec->envp);
	free(tmp_cmd);
	if (exec->arg->cmd[0] == 0)
	{
		return (127);
	}
	ret = execve(exec->arg->cmd[0], exec->arg->cmd, exec->envp);
	if (ret < 0)
	{
		ft_printf("bash: command not found\n");
	}
	return (127);
}
