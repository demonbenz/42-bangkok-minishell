/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:55:41 by schaisil          #+#    #+#             */
/*   Updated: 2022/06/09 16:19:30 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p_remove;

	while (*lst != NULL)
	{
		p_remove = *lst;
		*lst = (*lst)->next;
		(*del)((p_remove)->content);
		free(p_remove);
	}
}
