/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:26:13 by schaisil          #+#    #+#             */
/*   Updated: 2022/07/07 13:45:43 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_fd(unsigned int n, int fd)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n > 15)
	{
		ft_puthex_fd(n / 16, fd);
		ft_puthex_fd(n % 16, fd);
	}
	else
	{
		write(fd, &hex[n], 1);
	}
}
