/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:43:25 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/15 07:08:54 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	ms_parser(t_lstr *words, t_info *info)
{
	while (words != NULL)
	{
		if (is_expand_home(words->c, info))
		{
			free(words->c);
			words->c = create_value_from_env_key("HOME=", info->envs);
		}
		else
		{
			parse_word(words, info);
		}
		words = words->next;
	}
}

// assume 1 expanded word no longer than 500 bytes
void	parse_word(t_lstr *words, t_info *info)
{
	int	i;
	int	j;

	info->parse_in = words->c;
	info->parse_out = strdup_big("", 500);
	i = 0;
	j = 0;
	while (info->parse_in[i] != '\0')
	{
		if (info->parse_in[i] == '\'')
			dequote_sq(info, &i, &j);
		else if (info->parse_in[i] == '"')
			dequote_dq(info, &i, &j);
		else if (info->parse_in[i] == '$')
			expand_var(info, &i, &j);
		else
			info->parse_out[j++] = info->parse_in[i++];
	}
	free(words->c);
	words->c = info->parse_out;
}

void	dequote_sq(t_info *info, int *i, int *j)
{
	int	wlen;
	int	k;

	wlen = len_word_in_quote(info->parse_in + *i);
	k = 0;
	(*i)++;
	while (k < wlen)
	{
		info->parse_out[*j] = info->parse_in[*i];
		k++;
		(*j)++;
		(*i)++;
	}
	(*i)++;
}

void	dequote_dq(t_info *info, int *i, int *j)
{
	int		wlen;
	int		k;
	char	*key;

	wlen = len_word_in_quote(info->parse_in + *i);
	k = 0;
	(*i)++;
	while (k < wlen)
	{
		if (info->parse_in[*i] == '$')
		{
			key = create_first_env_key(info->parse_in + *i);
			k += ft_strlen(key);
			free(key);
			expand_var(info, i, j);
		}
		else
		{
			info->parse_out[(*j)++] = info->parse_in[(*i)++];
			k++;
		}
	}
	(*i)++;
}

// assume paired quote
// assume start with ' or "
int	len_word_in_quote(char *str)
{
	int	i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == str[0])
			break ;
		i++;
	}
	return (i - 1);
}
