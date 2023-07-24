/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 06:56:52 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/08 14:01:41 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bi_cmds.h"
#include "minishell.h"

int	run_env(char **cmd, char **envs)
{
	int	i;

	if (cmd[1] != NULL)
		return (ft_printf("%s\n", ERR_EXC0), 1);
	i = 0;
	while (envs[i] != NULL)
	{
		ft_printf("%s\n", envs[i]);
		i++;
	}
	return (1);
}

int	run_pwd(void)
{
	char	*pwd;

	pwd = (char *)ft_calloc(1024, sizeof(char));
	if (pwd != NULL)
	{
		getcwd(pwd, 1024);
		ft_printf("%s\n", pwd);
		free(pwd);
		return (1);
	}
	else
		return (ft_printf("%s", ERR_MEM), -1);
}
