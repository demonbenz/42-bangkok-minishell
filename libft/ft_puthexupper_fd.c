/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexupper_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:39:55 by schaisil          #+#    #+#             */
/*   Updated: 2022/07/07 13:46:30 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexupper_fd(unsigned int n, int fd)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_puthexupper_fd(n / 16, fd);
		ft_puthexupper_fd(n % 16, fd);
	}
	else
	{
		write(fd, &hex[n], 1);
	}
}
