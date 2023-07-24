/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_ctab_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:11:23 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/24 22:18:24 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

t_cmd	**create_command_table(char *line, t_info *info)
{
	t_lstr	*words;
	t_lstr	**lcmds;
	t_cmd	**ctabs;

	words = ms_lexer(line);
	free(line);
	if (ms_check_grammar(words) == -1)
		return (lstr_free(&words), NULL);
	ms_parser(words, info);
	lcmds = pipe_cuts(words, info);
	if (lcmds == NULL)
		return (lstr_free(&words), NULL);
	lstr_free(&words);
	ctabs = create_cmd_table(lcmds, info->total_cmds);
	free_lcmds(lcmds, info->total_cmds);
	return (ctabs);
}
// ft_printf("lexer_out: ");
// lstr_print(words);
// ft_printf("parser_out: ");
// lstr_print(words);
// ft_printf("pipe_cuts: ");
// print_lcmds(lcmds, info->total_cmds);
// ft_printf("ctabs: ");
// print_ctabs(ctabs, info->total_cmds);

char	**extract_cmd(t_lstr **lstr_rf)
{
	t_lstr	*lst;
	char	**result;
	int		i;
	int		count;

	lst = *lstr_rf;
	if (lst == NULL)
	{
		result = (char **) malloc (sizeof(char *) * (1));
		result[0] = NULL;
		return (result);
	}
	count = lstr_count(lst);
	result = (char **) malloc (sizeof(char *) * (count + 1));
	result[count] = NULL;
	i = 0;
	while (lst != NULL)
	{
		result[i] = ft_strdup(lst->c);
		i++;
		lst = lst->next;
	}
	return (result);
}

void	free_ctabs(t_cmd **ctabs, int total_cmds)
{
	int	i;

	i = 0;
	while (i < total_cmds)
	{
		if (ctabs[i] != NULL)
		{
			if (ctabs[i]->infile_sym != NULL)
				free_split(ctabs[i]->infile_sym);
			if (ctabs[i]->outfile_sym != NULL)
				free_split(ctabs[i]->outfile_sym);
			if (ctabs[i]->heredoc_sym != NULL)
				free_split(ctabs[i]->heredoc_sym);
			if (ctabs[i]->append_sym != NULL)
				free_split(ctabs[i]->append_sym);
			if (ctabs[i]->cmd != NULL)
				free_split(ctabs[i]->cmd);
			free(ctabs[i]);
		}
		i++;
	}
	free(ctabs);
}

void	free_ctab(void *content)
{
	if (content)
	{
	}
}

t_list	*create_list_ctabs(t_cmd **ctabs, int total_cmds)
{
	t_list	*result;
	int		i;
	t_list	*item;

	result = NULL;
	i = 0;
	while (i < total_cmds)
	{
		item = ft_lstnew(ctabs[i]);
		ft_lstadd_back(&result, item);
		i++;
	}
	return (result);
}
