/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:22:32 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/16 16:27:33 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

// note: handle? case null/empty key
char	*create_value_from_env_key(char *key, char **envs)
{
	char	*result;
	int		len_key;
	int		i;

	result = NULL;
	len_key = ft_strlen(key);
	i = 0;
	while (envs[i] != NULL)
	{
		if (ft_isequalstrn(envs[i], key, len_key))
		{
			result = ft_strdup(envs[i] + len_key);
			break ;
		}
		i++;
	}
	if (result == NULL)
		result = ft_strdup("");
	return (result);
}

// from word input, which may contain multiple key
// ie. echo $SHELL-$SHELL -> /bin/zsh-/bin/zsh
// create the first key $SHELL as [SHELL=]
// logic:
// calculate len of key
// 		- scan each char in str
// 		- stop when found $, ', "
// 		- stop when character is not alpha_numberic and not '_'

// look like len can be calculate with just $ and alphanum
// assume: atleast first char is $ (has pre-check)
// note: support 4 case includes $, $$, $var, $unkown_var
char	*try_create_first_env_key_short(char *str)
{
	if (ft_isequalstrn(str, "$$", 2))
		return (ft_strdup("$$"));
	if (ft_isequalstrn(str, "$?", 2))
		return (ft_strdup("$?"));
	if (ft_isequalstrn(str, "$", 0))
		return (ft_strdup("$"));
	return (NULL);
}

int	len_first_env_key(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (ft_strchr("$'\"", str[i]) != NULL)
			break ;
		if (!ft_isalnum(str[i]) && str[i] != '_')
			break ;
		i++;
	}
	return (i - 1);
}

char	*create_first_env_key(char *str)
{
	int		i;
	int		j;
	int		len_env_key;
	char	*result;

	i = 1;
	result = try_create_first_env_key_short(str);
	if (result != NULL)
		return (result);
	len_env_key = len_first_env_key(str, i);
	if (len_env_key == 0)
		return (ft_strdup("$"));
	result = malloc(len_env_key + 2);
	j = 0;
	i = 1;
	while (j < len_env_key)
	{
		result[j] = str[i];
		i++;
		j++;
	}
	result[j] = '=';
	result[j + 1] = '\0';
	return (result);
}
