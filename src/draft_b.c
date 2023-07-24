/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:02:42 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/16 16:02:35 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	print_lcmds(t_lstr **lcmds, int total_cmds)
{
	int	i;

	i = 0;
	while (i < total_cmds)
	{
		lstr_print(lcmds[i]);
		i++;
	}
}

void	print_ctab_and_option(char *str, char **options)
{
	ft_printf("%s", str);
	print_options(options);
}

void	print_ctabs(t_cmd **ctabs, int total_cmds)
{
	t_cmd	*ct;
	int		i;
	int		j;

	i = 0;
	while (i < total_cmds)
	{
		ct = ctabs[i];
		j = 0;
		ft_printf("\ni: %d", i);
		if (ctabs[i]->cmd[0] != NULL)
			print_ctab_and_option("\ncmd: ", ctabs[i]->cmd);
		if (ctabs[i]->infile_sym[0] != NULL)
			print_ctab_and_option("\ninfile: ", ctabs[i]->infile_sym);
		if (ctabs[i]->outfile_sym[0] != NULL)
			print_ctab_and_option("\noutfile: ", ctabs[i]->outfile_sym);
		if (ctabs[i]->heredoc_sym[0] != NULL)
			print_ctab_and_option("\nheredoc: ", ctabs[i]->heredoc_sym);
		if (ctabs[i]->append_sym[0] != NULL)
			print_ctab_and_option("\nappend: ", ctabs[i]->append_sym);
		ft_printf("\n");
		i++;
	}
}

void	print_options(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		ft_printf("%s ", strs[i]);
		i++;
	}
}

char	**strs_dup(char **strs)
{
	char	**result;
	int		count;
	int		i;

	if (strs == NULL)
		return (NULL);
	count = 500;
	result = malloc(sizeof(char *) * (count + 1));
	if (result != NULL)
	{
		i = 0;
		while (i < (count + 1))
		{
			result[i] = NULL;
			i++;
		}
		i = 0;
		while (strs[i] != NULL)
		{
			result[i] = ft_strdup(strs[i]);
			i++;
		}
	}
	return (result);
}
