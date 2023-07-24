/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstr_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:22:39 by schaisil          #+#    #+#             */
/*   Updated: 2023/05/05 12:51:48 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lstr.h"

t_lstr	*lstr_new_item(char *str)
{
	t_lstr	*item;

	item = malloc(sizeof(t_lstr));
	if (item != NULL)
	{
		item->c = str;
		item->next = NULL;
	}
	return (item);
}

t_lstr	*lstr_last(t_lstr *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lstr_add_back(t_lstr **lst_rf, t_lstr *new_item)
{
	if (*lst_rf != NULL)
		(lstr_last(*lst_rf))->next = new_item;
	else
		*lst_rf = new_item;
}

void	lstr_free(t_lstr **lst_rf)
{
	t_lstr	*p_remove;

	while (*lst_rf != NULL)
	{
		p_remove = *lst_rf;
		*lst_rf = (*lst_rf)->next;
		free(p_remove->c);
		free(p_remove);
	}
	*lst_rf = NULL;
}
