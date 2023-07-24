/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstr_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:27:15 by schaisil          #+#    #+#             */
/*   Updated: 2023/06/28 13:21:03 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lstr.h"

int	lstr_count(t_lstr *lst)
{
	int	count;

	if (lst == NULL)
		return (0);
	count = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	lstr_print(t_lstr *lst)
{
	int	i;
	int	count;

	i = 0;
	count = lstr_count(lst);
	while (i < count)
	{
		ft_printf("[%s]", lst->c);
		if (i == count - 1)
			ft_printf("\n");
		else
			ft_printf(" -> ");
		lst = lst->next;
		i++;
	}
}

t_lstr	*lstr_dup(t_lstr *lst)
{
	t_lstr	*result;
	char	*str;

	result = NULL;
	while (lst != NULL)
	{
		str = ft_strdup(lst->c);
		lstr_add_back(&result, lstr_new_item(str));
		lst = lst->next;
	}
	return (result);
}

void	lstr_remove_next(t_lstr **lst_rf)
{
	t_lstr	*remove;

	remove = (*lst_rf)->next;
	(*lst_rf)->next = remove->next;
	free(remove->c);
	free(remove);
}

void	lstr_remove_two(t_lstr **lst_rf, t_lstr *prev)
{
	t_lstr	*remove;
	t_lstr	*remove2;

	remove = *lst_rf;
	remove2 = (*lst_rf)->next;
	*lst_rf = (*lst_rf)->next->next;
	if (prev != NULL)
		prev->next = *lst_rf;
	free(remove->c);
	free(remove);
	free(remove2->c);
	free(remove2);
}
