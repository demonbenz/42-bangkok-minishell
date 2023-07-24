/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 04:51:52 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/23 18:29:38 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

// note: run in child_process
// case_0: export
void	run_export_no_arg(t_exec *exec)
{
	int		i;
	int		j;
	char	**envp_dup;

	envp_dup = strs_dup(exec->envp);
	sort_dubb_ptr(envp_dup);
	i = 0;
	while (envp_dup[i] != NULL)
	{
		write(1, "declare -x ", 11);
		j = 0;
		while (envp_dup[i][j] != '=' && envp_dup[i][j] != '\0')
			write(1, &envp_dup[i][j++], 1);
		j++;
		write(1, "=\"", 2);
		while (envp_dup[i][j] != '\0')
			write(1, &envp_dup[i][j++], 1);
		write(1, "\"\n", 2);
		i++;
	}
	free_dubptr(envp_dup);
}

// note: run in parent_process
// case_1: export =			// err_msg
// case_2: export a[		// err_msg
// case_3: export a			// do nothing
// case_4: export a = 5		// 2x err_msg
// case_5: export a=		// set a (empty)
// case_6: export a=5		// set a
// case_7: export a=2 b=3	// set a, set b
// case_8: export a==5      // set a [=5]
// case_8: export a=#@_%+-=/1 // set a [#@_%+-=/1]
// assume pre-check have atleast 1 arg
void	run_export_with_arg(t_exec *exec)
{
	int		i;
	int		total_arg;
	char	*str;

	i = 2;
	while (exec->arg->cmd[i] != NULL)
		i++;
	total_arg = i - 1;
	i = 1;
	while (i < total_arg + 1)
	{
		str = exec->arg->cmd[i++];
		if (check_export_arg(str) == -1)
		{
			*exec->cmd_exit_num = 1;
			continue ;
		}
		if (ft_strchr(str, '=') == NULL)
		{
			*exec->cmd_exit_num = 1;
			continue ;
		}
		match_command(exec, str);
		*exec->cmd_exit_num = 0;
	}
}

int	check_export_arg(char *str)
{
	int	i;

	if (!ft_isalpha(str[0]) && str[0] != '_')
	{
		ft_printf("bash: export: `%s': not a valid identifier\n", str);
		return (-1);
	}
	i = 1;
	while (str[i] != '\0')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_' && str[i] != '=')
		{
			ft_printf("bash: export: `%s': not a valid identifier\n", str);
			return (-1);
		}
		if (str[i] == '=')
			break ;
		i++;
	}
	return (0);
}
