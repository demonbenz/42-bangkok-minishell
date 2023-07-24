/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:15:10 by otangkab          #+#    #+#             */
/*   Updated: 2023/07/24 22:38:41 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "libft.h"

int	is_include_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	print_error_msg(char *msg)
{
	ft_printf("bash: ");
	perror(msg);
	return (-1);
}

void	free_2_value(char *str1, char *str2)
{
	free(str1);
	free(str2);
}

void	handle_quit(int signum)
{
	if (signum == SIGQUIT)
		exit(131);
}

void	handle_interrupt(int signum)
{
	if (signum == SIGINT)
		exit(1);
}
