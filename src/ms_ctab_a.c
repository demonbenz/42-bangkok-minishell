/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_ctab_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:15:00 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/23 15:10:43 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

// assume: list always have content on the node after opt (already pre-validate)
char	**extract_options(t_lstr **lst_rf, char *opt)
{
	char	**result;
	t_lstr	*lst;
	t_lstr	*prev;
	int		i;

	lst = *lst_rf;
	prev = NULL;
	allocate_options(&result, lst, opt);
	i = 0;
	while (lst != NULL)
	{
		if (ft_isequalstrn(lst->c, opt, 0))
		{
			extract_opt(result, &lst, &i, prev);
			if (prev == NULL)
				*lst_rf = lst;
		}
		else
		{
			prev = lst;
			lst = lst->next;
		}
	}
	return (result);
}

void	allocate_options(char ***result, t_lstr *lst, char *opt)
{
	int	total_opts;
	int	i;

	total_opts = count_options(lst, opt);
	*result = (char **) malloc (sizeof(char *) * (total_opts + 1));
	i = 0;
	while (i < total_opts + 1)
	{
		(*result)[i] = NULL;
		i++;
	}
}

int	count_options(t_lstr *lst, char *opt)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		if (ft_isequalstrn(lst->c, opt, 0))
			count++;
		lst = lst->next;
	}
	return (count);
}

void	extract_opt(char **result, t_lstr **lst, int *i, t_lstr *prev)
{
	t_lstr	*remove;
	t_lstr	*remove2;

	result[*i] = ft_strdup((*lst)->next->c);
	(*i)++;
	remove = *lst;
	remove2 = (*lst)->next;
	*lst = (*lst)->next->next;
	if (prev != NULL)
		prev->next = *lst;
	free(remove->c);
	free(remove);
	free(remove2->c);
	free(remove2);
}
