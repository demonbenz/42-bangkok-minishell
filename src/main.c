/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:50:53 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/23 16:43:55 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <readline/history.h>

int	main(int argc, char **argv, char **envs)
{
	t_info	info;

	if (argc != 1)
		return (ft_printf("how to start: ./minishell\n"), -1);
	print_welcome_text();
	ms_init(&info, envs);
	ms_prompt_loop(&info);
	ms_clear(&info);
	return (ft_printf("exit\n"), info.app_exit_num);
	(void)argv;
}

void	ms_init(t_info *info, char **envs)
{
	info->envs = strs_dup(envs);
	info->exit = 0;
	info->app_exit_num = 0;
	info->cmd_exit_num = 0;
	info->total_cmds = 0;
	init_signal(info);
	set_echo_ctl(DISABLE);
}

void	ms_clear(t_info *info)
{
	free_info(info);
	set_echo_ctl(ENABLE);
	rl_clear_history();
}
