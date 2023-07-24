/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 07:25:45 by schaisil          #+#    #+#             */
/*   Updated: 2022/06/18 04:43:18 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// note: iterate through each node in the list, apply function 'f'
//       allocate & create new list contain the the result
//       return the new list
//       deallocate node & use del to delete node content if necessary
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p_result;
	t_list	*p_new;
	t_list	*p_start;
	void	*p_content_new;

	p_new = NULL;
	p_result = NULL;
	p_start = lst;
	while (lst != NULL)
	{
		p_content_new = (*f)(lst->content);
		p_new = ft_lstnew(p_content_new);
		if (p_new == NULL)
		{
			ft_lstclear(&p_start, del);
			return (NULL);
		}
		ft_lstadd_back(&p_result, p_new);
		lst = lst->next;
	}
	return (p_result);
}

// example of input function
// static void	*f(void *content)
// {
// 	*((int *) content) = *((int *) content) + 42;
// 	return content;
// }
// static void	del(void *content)
// {
// 	free(content);
// }
/*
		this code use for simulate, unable to malloc at node 4 in the list
		if (*(int *)p_content_new == 142)
		{
			printf("*** cannot allocate new node ***\n");
		 	ft_lstclear(&p_start, del);
			return NULL;
		}
*/
