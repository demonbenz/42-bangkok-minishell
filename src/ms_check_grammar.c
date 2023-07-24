/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_check_grammar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:09:32 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/24 22:06:40 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int	ms_check_grammar(t_lstr *words)
{
	char	*current_word;
	char	*next_word;
	t_lstr	*lst;

	lst = words;
	if (ft_isequalstrn(lst->c, "|", 0))
		return (ft_printf("%s", ERR_LEX2), -1);
	if (count_pipe(words) + 1 > TOTAL_CMDS_SUPPORTED)
		return (ft_printf("%s", ERR_LEX3), -1);
	while (lst != NULL)
	{
		current_word = lst->c;
		if (is_unsupported_opt(current_word))
			return (ft_printf("%s%s\n", ERR_LEX0, current_word), -1);
		if (is_unpaired_quote(current_word))
			return (ft_printf("%s%s\n", ERR_LEX1, current_word), -1);
		if (lst->next != NULL)
			next_word = lst->next->c;
		else
			next_word = NULL;
		if (is_opt_with_invalid_arg(current_word, next_word))
			return (ft_printf("%s", ERR_LEX2), -1);
		lst = lst->next;
	}
	return (0);
}

int	is_unsupported_opt(char *str)
{
	return (ft_isequalstrn(str, "&", 0) || ft_isequalstrn(str, "&&", 0) || \
			ft_isequalstrn(str, "||", 0));
}

int	is_unpaired_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			skip_to_ending_quote(str, &i);
			if (str[i] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

void	skip_to_ending_quote(char *str, int *i)
{
	char	quote;

	quote = str[*i];
	(*i)++;
	while (str[*i] != '\0' && str[*i] != quote)
		(*i)++;
}

int	is_opt_with_invalid_arg(char *opt, char *opt_arg)
{
	if (!is_opt(opt))
		return (0);
	if (opt_arg == NULL || is_opt(opt_arg))
		return (1);
	return (0);
}
