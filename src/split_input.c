/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:45:42 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/23 19:23:57 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

// note: assume str is not null/empty
//       assume str is trimed (has no white spaces in front/back)
t_lstr	*split_input(char *str)
{
	t_lstr	*words;
	int		i;
	int		len;
	char	*word;

	words = NULL;
	i = 0;
	while (str[i] != '\0')
	{
		len = len_word(str + i);
		word = ft_substr(str + i, 0, len);
		lstr_add_back(&words, lstr_new_item(word));
		i += len;
		while (str[i] == ' ' || str[i] == '\t')
			i++;
	}
	return (words);
}

// note: assume trimed white_space from front & back of str
int	len_word(char *str)
{
	int	i;

	if (ft_isequalstrn(str, "", 1))
		return (0);
	else if (ft_isequalstrn(str, "<<", 2) || ft_isequalstrn(str, ">>", 2))
		return (2);
	else if (ft_isequalstrn(str, "<", 1) || ft_isequalstrn(str, ">", 1))
		return (1);
	else if (ft_isequalstrn(str, "||", 2) || ft_isequalstrn(str, "&&", 2))
		return (2);
	else if (ft_isequalstrn(str, "|", 1) || ft_isequalstrn(str, "&", 1))
		return (1);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(" \n\t<>|&", str[i]) != NULL)
			break ;
		if (str[i] == '\'' || str[i] == '"')
			i += len_quote(&str[i]);
		else
			i++;
	}
	return (i);
}

// note: assume str[0] is ['] or ["]
//       handle ['abc def'] -> len(9), reach ['] end_pair
//       handle ['abc"  "] -> len(8), reach '\0'
int	len_quote(char *str)
{
	int	i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == str[0])
			break ;
		i++;
	}
	if (str[i] == '\0')
		return (i);
	return (i + 1);
}
