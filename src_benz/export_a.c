/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:40:03 by otangkab          #+#    #+#             */
/*   Updated: 2023/07/18 06:26:11 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	sort_dubb_ptr(char **envp_dup)
{
	char	*tmp;
	int		i;
	int		j;
	int		less_len;

	tmp = NULL;
	i = -1;
	j = 0;
	while (envp_dup[++i + 1] != NULL)
	{
		j = i;
		while (envp_dup[++j] != NULL)
		{
			if (ft_strlen(envp_dup[i]) < ft_strlen(envp_dup[j]))
				less_len = ft_strlen(envp_dup[i]);
			else
				less_len = ft_strlen(envp_dup[j]);
			if (ft_strncmp(envp_dup[i], envp_dup[j], less_len) > 0)
			{
				tmp = envp_dup[i];
				envp_dup[i] = envp_dup[j];
				envp_dup[j] = tmp;
			}
		}
	}
}

char	*find_keyword(char *str, char c)
{
	char	*key;
	int		i;

	key = NULL;
	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	key = (char *)ft_calloc(i + 2, sizeof(char));
	if (!key)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		key[i] = str[i];
		i++;
	}
	key[i] = c;
	return (key);
}

int	match_command(t_exec *exec, char *str)
{
	int		i;
	int		len;
	char	*keyword;

	keyword = find_keyword(str, '=');
	len = ft_strlen(keyword);
	i = 0;
	while (exec->envp[i] != NULL)
	{
		if (ft_strncmp(keyword, exec->envp[i], len) == 0)
		{
			free(exec->envp[i]);
			exec->envp[i] = ft_strdup(str);
			free(keyword);
			return (1);
		}
		i++;
	}
	free(keyword);
	exec->envp[i] = ft_strdup(str);
	return (0);
}
