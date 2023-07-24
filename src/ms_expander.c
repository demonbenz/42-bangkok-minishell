/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:46:30 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/24 21:49:07 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

// required expand only 2 cases
// 1. ~ -> [/Users/schaisil]
// 2. ~schaisil -> [/Users/schaisil]
// no need to expand
// ~s -> [~s]
// ~schaisils [~schaisils]
int	is_expand_home(char *word, t_info *info)
{
	char	*user_id;

	if (word == NULL)
		return (0);
	if (ft_isequalstrn(word, "~", 0))
		return (1);
	user_id = create_value_from_env_key("USER=", info->envs);
	if (word[0] == '~' && ft_isequalstrn(word + 1, user_id, 0))
		return (free(user_id), 1);
	else
		return (free(user_id), 0);
}

// note: support 4 case includes $, $$, $var, $unkown_var
void	expand_var(t_info *info, int *i, int *j)
{
	char	*key;
	char	*val;
	int		x;

	key = create_first_env_key(info->parse_in + *i);
	if (ft_isequalstrn(key, "$$", 0))
		val = ft_itoa(getpid());
	else if (ft_isequalstrn(key, "$?", 0))
		val = ft_itoa(info->cmd_exit_num);
	else if (ft_isequalstrn(key, "$", 0))
		val = ft_strdup("$");
	else
		val = create_value_from_env_key(key, info->envs);
	x = 0;
	while (val[x] != '\0')
	{
		info->parse_out[*j] = val[x];
		(*j)++;
		x++;
	}
	(*i) += ft_strlen(key);
	free(key);
	free(val);
}
// ft_printf("p_exit: [%d]\n", info->exit);
// ft_printf("p_exit: [%d]\n", info->exit_num);
