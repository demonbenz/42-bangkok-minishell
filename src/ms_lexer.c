/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:27:01 by schaisil          #+#    #+#             */
/*   Updated: 2023/06/24 15:47:34 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

t_lstr	*ms_lexer(char *line)
{
	char	*trim_line;
	t_lstr	*words;

	trim_line = ft_strtrim(line, " \t");
	words = split_input(trim_line);
	free(trim_line);
	return (words);
}

void	ms_clean_loop(char *str, t_lstr **lst_rf)
{
	free(str);
	lstr_free(lst_rf);
}
