/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:25:01 by schaisil          #+#    #+#             */
/*   Updated: 2023/06/28 10:39:11 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTR_H
# define LSTR_H

typedef struct s_lstr	t_lstr;
struct s_lstr
{
	char	*c;
	t_lstr	*next;
};

t_lstr	*lstr_new_item(char *str);
t_lstr	*lstr_last(t_lstr *lst);
void	lstr_add_back(t_lstr **lst_rf, t_lstr *new_item);
void	lstr_print(t_lstr *lst);
void	lstr_free(t_lstr **lst_rf);
int		lstr_count(t_lstr *lst);
t_lstr	*lstr_dup(t_lstr *lst);
void	lstr_remove_next(t_lstr **lst_rf);

#endif
