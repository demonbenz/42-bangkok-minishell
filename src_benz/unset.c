/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <otangkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:55:52 by otangkab          #+#    #+#             */
/*   Updated: 2023/07/10 22:58:53 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	run_unset(t_exec *exec)
{
	int		i;
	int		len;
	char	*key;

	if (exec->arg->cmd[1] == NULL)
		return ;
	key = ft_strjoin(exec->arg->cmd[1], "=");
	len = ft_strlen(key);
	i = 0;
	while (exec->envp[i] != NULL)
	{
		if (ft_strncmp(key, exec->envp[i], len) == 0)
		{
			free(exec->envp[i]);
			while (exec->envp[i + 1] != NULL)
			{
				exec->envp[i] = exec->envp[i + 1];
				i++;
			}
			exec->envp[i] = NULL;
			break ;
		}
		i++;
	}
	free(key);
}
