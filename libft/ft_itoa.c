/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:59:29 by schaisil          #+#    #+#             */
/*   Updated: 2022/06/13 14:21:33 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_nbr(int n, char *s, int i, int len)
{
	if (n > 9)
	{
		print_nbr(n / 10, s, i + 1, len);
		print_nbr(n % 10, s, i, len);
	}
	else
		s[len - i] = '0' + n;
}

static void	print_min_integer(char *s)
{
	s[0] = '-';
	s[1] = '2';
	s[2] = '1';
	s[3] = '4';
	s[4] = '7';
	s[5] = '4';
	s[6] = '8';
	s[7] = '3';
	s[8] = '6';
	s[9] = '4';
	s[10] = '8';
	s[11] = '\0';
}

static int	count_integer_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len += 1;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

// note: allocate and return a string representing integer
//       negative number must be handle
//       convert any number from -2147483648 (min) to 2147483647 (max)
char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
	{
		str = (char *) malloc(12 * sizeof(char));
		if (str != NULL)
			print_min_integer(str);
		return (str);
	}
	len = count_integer_len(n);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (str != NULL)
	{
		if (n < 0)
		{
			str[0] = '-';
			print_nbr(-n, str, 1, len);
		}
		else
			print_nbr(n, str, 1, len);
		str[len] = '\0';
	}
	return (str);
}
