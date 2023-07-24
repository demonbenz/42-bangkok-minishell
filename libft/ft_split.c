/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 05:49:11 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/16 15:09:25 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int		i;
	int		wc;

	wc = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		else
			wc++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (wc);
}

static char	*create_item(char const *s, char c, int *i)
{
	int		len_split;
	char	*split;

	len_split = 0;
	while (s[*i] != '\0' && s[*i] != c)
	{
		len_split++;
		(*i)++;
	}
	split = (char *) malloc ((len_split + 1) * sizeof(char));
	if (split != NULL)
	{
		(*i) = (*i) - len_split;
		len_split = 0;
		while (s[*i] != '\0' && s[*i] != c)
		{
			split[len_split] = s[*i];
			len_split++;
			(*i)++;
		}
		split[len_split] = '\0';
	}
	return (split);
}

static void	free_previous_allocate_memory(char **mem, int w)
{
	int	i;

	i = 0;
	while (i < w)
	{
		free(mem[i]);
		i++;
	}
	free(mem);
	mem = NULL;
}

static char	**continue_split(char const *s, char c, char **result)
{
	int		i;
	int		w;

	i = 0;
	w = -1;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		else
			w++;
		result[w] = create_item(s, c, &i);
		if (result[w] == NULL)
		{
			free_previous_allocate_memory(result, w);
			return (NULL);
		}
	}
	return (result);
}

// note: allocate and return an array of strings result from split,
//       split 's' by using 'c' as a delimeter,
//       array must end with a NULL pointer
//       return NULL if allocation fail
char	**ft_split(char const *s, char c)
{
	int		wc;
	char	**result;

	if (s == NULL)
		return (NULL);
	wc = word_count(s, c);
	if (wc == 0)
	{
		result = (char **) malloc ((1) * sizeof(char *));
		if (result != NULL)
			result[0] = NULL;
	}
	else
	{
		result = (char **) malloc ((wc + 1) * sizeof(char *));
		if (result != NULL)
		{
			result = continue_split(s, c, result);
			if (result != NULL)
				result[wc] = NULL;
		}
	}
	return (result);
}
/*
		for test condition unable to allocate memory
		if (w == 3)
			result[w] = (char *) malloc (50000000000 * sizeof(char));
		else
			result[w] = create_item(s, c, &i);
		if (result[w] == NULL)
		{
			free_previous_allocate_memory(result, w);
			return (NULL);
		}
*/
