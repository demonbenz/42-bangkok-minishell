/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_ctab_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:08:37 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/23 15:10:38 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

t_cmd	**create_cmd_table(t_lstr **lcmds, int total_cmds)
{
	t_cmd	**ctabs;
	int		i;

	ctabs = malloc(sizeof(t_cmd *) * (total_cmds + 1));
	i = 0;
	while (i < total_cmds)
		ctabs[i++] = malloc(sizeof(t_cmd));
	ctabs[i] = NULL;
	create_cmd_table_part2(ctabs, lcmds, total_cmds);
	create_cmd_table_part3(ctabs, lcmds, total_cmds);
	return (ctabs);
}
//dprintf(2, "cmd[%d]last_in = [%d]<-\n", j, ctabs[j]->last_in);
//dprintf(2, "cmd[%d]last_out = [%d]<-\n", j, ctabs[j]->last_out);

void	create_cmd_table_part2(t_cmd **ctabs, t_lstr **lcmds, int total_cmds)
{
	t_lstr	*tmp_l;
	int		j;

	j = 0;
	while (j < total_cmds)
	{
		ctabs[j]->last_in = 0;
		ctabs[j]->last_out = 0;
		tmp_l = lcmds[j];
		while (tmp_l != NULL)
		{
			if (ft_isequalstrn(tmp_l->c, "<", 0))
				ctabs[j]->last_in = 1;
			else if (ft_isequalstrn(tmp_l->c, "<<", 0))
				ctabs[j]->last_in = 2;
			if (ft_isequalstrn(tmp_l->c, ">", 0))
				ctabs[j]->last_out = 3;
			else if (ft_isequalstrn(tmp_l->c, ">>", 0))
				ctabs[j]->last_out = 4;
			tmp_l = tmp_l->next;
		}
		j++;
	}
}

void	create_cmd_table_part3(t_cmd **ctabs, t_lstr **lcmds, int total_cmds)
{
	int	i;

	i = 0;
	while (i < total_cmds)
	{
		ctabs[i]->infile_sym = extract_options(&(lcmds[i]), "<");
		ctabs[i]->outfile_sym = extract_options(&(lcmds[i]), ">");
		ctabs[i]->heredoc_sym = extract_options(&(lcmds[i]), "<<");
		ctabs[i]->append_sym = extract_options(&(lcmds[i]), ">>");
		ctabs[i]->cmd = extract_cmd(&(lcmds[i]));
		i++;
	}
}

void	free_command_table(t_list **list_ctabs, t_cmd **ctabs, int total_cmds)
{
	free_ctabs(ctabs, total_cmds);
	ft_lstclear(list_ctabs, &free_ctab);
}
