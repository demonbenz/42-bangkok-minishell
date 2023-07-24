/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenllhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:56:37 by schaisil          #+#    #+#             */
/*   Updated: 2022/07/07 14:57:54 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_lenllhex(unsigned long long n)
{
	int	len;

	len = 1;
	while (n > 15)
	{
		n /= 16;
		len++;
	}
	return (len);
}