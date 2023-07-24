/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <otangkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:09:29 by otangkab          #+#    #+#             */
/*   Updated: 2023/07/24 14:53:23 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "libft.h"

void	free_dubptr(char **ptr)
{
	int	i;

	if (ptr[0] == 0)
		return ;
	i = 0;
	while (ptr[i])
	{
		free (ptr[i]);
		i++;
	}
	free (ptr);
}

char	*joinpath(char *cmd, char *path)
{
	char	*path_cmd;
	char	*path_slash;

	path_slash = ft_strjoin(path, "/");
	free(path);
	path_cmd = ft_strjoin(path_slash, cmd);
	free(path_slash);
	return (path_cmd);
}

char	**split_path(char **env)
{
	char	**tmp_set;
	char	*tmp;
	int		i;

	i = 0;
	while (env[i])
	{
		if ((env[i][0] == 'P') && (env[i][1] == 'A') \
				&& (env[i][2] == 'T') && (env[i][3] == 'H') \
				&& (env[i][4] == '='))
		{
			tmp_set = ft_split(env[i], ':');
			tmp = ft_strtrim(tmp_set[0], "PATH=");
			free(tmp_set[0]);
			tmp_set[0] = tmp;
			return (tmp_set);
		}
		i++;
	}
	return (0);
}

char	*findpath(char *cmd, char **envp)
{
	char	**tmp_set;
	char	*tmp;
	int		j;
	char	*joined;
	char	*joined2;

	tmp_set = split_path(envp);
	if (tmp_set == 0 || tmp_set[0] == 0)
		return (0);
	j = -1;
	while (tmp_set[++j])
	{
		joined = ft_strjoin(tmp_set[j], "/");
		joined2 = ft_strjoin(joined, cmd);
		if (access(joined2, F_OK) == 0)
		{
			free_2_value(joined, joined2);
			tmp = ft_strdup(tmp_set[j]);
			free_dubptr(tmp_set);
			return (tmp);
		}
		free_2_value(joined, joined2);
	}
	free_dubptr(tmp_set);
	return (0);
}

char	*check_path(char *cmd, char **envp)
{
	char	*path;

	path = 0;
	if (access(cmd, F_OK) == 0)
		return (cmd);
	else
	{
		path = findpath(cmd, envp);
		if (path == 0)
		{
			if (cmd[0] == '/')
				print_error_msg(cmd);
			else
				ft_printf("bash: %s: command not found\n", cmd);
			return (0);
		}
		cmd = joinpath(cmd, path);
		return (cmd);
	}
}
