/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe_cuts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:16:35 by schaisil          #+#    #+#             */
/*   Updated: 2023/06/29 06:56:52 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

t_lstr	**pipe_cuts(t_lstr *words, t_info *info)
{
	t_lstr	**lcmds;
	t_lstr	*copies;
	int		total_cmds;

	total_cmds = count_pipe(words) + 1;
	info->total_cmds = total_cmds;
	lcmds = malloc(sizeof(t_lstr *) * (total_cmds + 1));
	lcmds[total_cmds] = NULL;
	copies = lstr_dup(words);
	cuts_map_head(lcmds, copies);
	cuts_trim(lcmds);
	return (lcmds);
}

int	count_pipe(t_lstr *words)
{
	int	count;

	count = 0;
	while (words != NULL)
	{
		if (ft_isequalstrn(words->c, "|", 0))
			count++;
		words = words->next;
	}
	return (count);
}

// assume: words has atleast 1 cmd
void	cuts_map_head(t_lstr **lcmds, t_lstr *lst)
{
	int		i;

	lcmds[0] = lst;
	i = 1;
	while (lst != NULL)
	{
		if (ft_isequalstrn(lst->c, "|", 0))
		{
			lcmds[i] = lst->next;
			i++;
		}
		lst = lst->next;
	}
}

void	cuts_trim(t_lstr **lcmds)
{
	t_lstr	*lst;
	int		i;

	i = 0;
	while (lcmds[i] != NULL)
	{
		lst = lcmds[i];
		while (lst != NULL)
		{
			if (lst->next == NULL)
				break ;
			if (ft_isequalstrn(lst->next->c, "|", 0))
			{
				lstr_remove_next(&lst);
				lst->next = NULL;
				break ;
			}
			lst = lst->next;
		}
		i++;
	}
}

void	free_lcmds(t_lstr **lcmds, int total_cmds)
{
	int	i;

	i = 0;
	while (i < total_cmds)
	{
		lstr_free(lcmds + i);
		i++;
	}
	free(lcmds);
}
