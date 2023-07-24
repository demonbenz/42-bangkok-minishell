/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_inbound.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:27:01 by schaisil          #+#    #+#             */
/*   Updated: 2023/03/20 17:27:03 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_str_inbound(char *str)
{
	long	total;
	long	bound;
	int		i;

	if (str[0] == '-')
		bound = 2147483648;
	else
		bound = 2147483647;
	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	total = 0;
	while (str[i] != '\0')
	{
		total = total * 10 + str[i] - '0';
		if (total > bound)
			return (0);
		i++;
	}
	return (1);
}
