/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:47:30 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/23 16:51:11 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int	ms_prompt_loop(t_info *info)
{
	char	*line;
	t_cmd	**ctabs;
	t_list	*list_ctabs;

	while (!(info->exit))
	{
		line = readline("\033[1;32mbash-ms-$\033[0m ");
		if (line == NULL)
			break ;
		if (is_empty_input(line))
		{
			free(line);
			continue ;
		}
		add_history(line);
		ctabs = create_command_table(line, info);
		if (ctabs == NULL)
			continue ;
		list_ctabs = create_list_ctabs(ctabs, info->total_cmds);
		ms_executor(list_ctabs, info);
		free_command_table(&list_ctabs, ctabs, info->total_cmds);
	}
	return (0);
}
// char *str = ft_strjoin(ft_itoa(pi), "\033[1;32mbash-ms-$\033[0m ");
// (info->exit)=1;
// ft_printf("after exec exit= %d<\n", info->exit);
// ft_printf("after exec app_exit_num= %d<\n", info->app_exit_num);
// ft_printf("after exec cmd_exit_num= %d<\n", info->cmd_exit_num);
