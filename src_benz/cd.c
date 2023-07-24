/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:01:34 by otangkab          #+#    #+#             */
/*   Updated: 2023/07/23 18:12:08 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*get_var(char **envp, char *var)
{
	char	*pwd;
	int		i;
	int		j;
	int		k;
	int		len;

	pwd = NULL;
	i = -1;
	while (envp[++i] != NULL)
	{
		if (ft_strncmp(envp[i], var, ft_strlen(var)) == 0)
		{
			len = ft_strlen(envp[i]);
			j = 0;
			while ((envp[i][j++] != '/') && (envp[i][j] != '\0'))
				len--;
			pwd = (char *)ft_calloc(len + 1, sizeof(char));
			j--;
			k = 0;
			while (envp[i][j] != '\0')
				pwd[k++] = envp[i][j++];
			break ;
		}
	}
	return (pwd);
}

void	update_old_new_pwd(t_exec *exec)
{
	char	*path;
	char	*curr_path;
	int		i;

	curr_path = (char *)malloc(sizeof(char) * 2000);
	path = get_var(exec->envp, "PWD=");
	i = -1;
	while (exec->envp[++i] != NULL)
	{
		if (ft_strncmp(exec->envp[i], "OLDPWD=", 7) == 0)
			break ;
	}
	free(exec->envp[i]);
	exec->envp[i] = ft_strjoin("OLDPWD=", path);
	i = -1;
	while (exec->envp[++i] != NULL)
	{
		if (ft_strncmp(exec->envp[i], "PWD=", 4) == 0)
			break ;
	}
	free(exec->envp[i]);
	exec->envp[i] = ft_strjoin("PWD=", getcwd(curr_path, 2000));
	free(path);
	free(curr_path);
}

void	try_change_dir(char *path, t_exec *exec)
{
	if (ft_isequalstrn(path, "", 0))
	{
		*exec->cmd_exit_num = 0;
		return ;
	}
	if (chdir(path) != 0)
	{
		write(2, "bash: cd: ", 10);
		perror(exec->arg->cmd[1]);
		*exec->cmd_exit_num = 1;
	}
	else
	{
		update_old_new_pwd(exec);
		*exec->cmd_exit_num = 0;
	}
}

int	run_cd(t_exec *exec)
{
	char	*path;

	if (exec->arg->cmd[1] == NULL)
	{
		path = get_var(exec->envp, "HOME=");
		if (path == NULL)
		{
			write(2, "bash: cd: HOME not set\n", 23);
			*exec->cmd_exit_num = 1;
		}
		else
		{
			try_change_dir(path, exec);
			free(path);
		}
	}
	else
	{
		try_change_dir(exec->arg->cmd[1], exec);
	}
	return (0);
}
// ft_printf("path: [%s]\n", path);
