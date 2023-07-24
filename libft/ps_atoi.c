/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:24:46 by schaisil          #+#    #+#             */
/*   Updated: 2023/03/20 17:25:03 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ps_atoi(char *str)
{
	int	total;
	int	i;
	int	factor;

	i = 0;
	factor = 1;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[0] == '-')
		factor = -1;
	total = 0;
	while (str[i] != '\0')
	{
		total = total * 10 + str[i] - '0';
		i++;
	}
	return (total * factor);
}
