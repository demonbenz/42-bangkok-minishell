/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putllhex_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 04:35:15 by schaisil          #+#    #+#             */
/*   Updated: 2022/07/08 14:43:11 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putllhex_fd(unsigned long long n, int fd)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n > 15)
	{
		ft_putllhex_fd(n / 16, fd);
		ft_putllhex_fd(n % 16, fd);
	}
	else
	{
		write(fd, &hex[n], 1);
	}
}
