/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 08:02:55 by schaisil          #+#    #+#             */
/*   Updated: 2022/06/18 05:17:05 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_nbr(char c)
{
	return (c >= '0' && c <= '9');
}

static int	is_whitespace(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

static int	is_beyond_longlongint(const char *str, int i)
{
	unsigned long long int	total;

	total = 0;
	while (str[i] != '\0' && is_nbr(str[i]))
	{
		total = total * 10 + str[i] - '0';
		i++;
		if (total > 9223372036854775807)
			return (1);
	}
	return (0);
}

static int	result_beyond_longlongint(int factor)
{
	if (factor == 1)
		return (-1);
	else
		return (0);
}

// note: convert str to integer, remove white space in front, handle +/-
//       isspace include '\t', '\n', '\v', '\f', '\r', ' ' 
//       overflow case match libc, beyond long long int case match libc
int	ft_atoi(const char *str)
{
	int	i;
	int	factor;
	int	total;

	i = 0;
	while (is_whitespace(str[i]))
		i++;
	factor = 1;
	if (str[i] == '-')
	{
		factor = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	total = 0;
	if (is_beyond_longlongint(str, i))
		return (result_beyond_longlongint(factor));
	while (str[i] != '\0' && is_nbr(str[i]))
	{
		total = total * 10 + str[i] - '0';
		i++;
	}
	return (total * factor);
}
