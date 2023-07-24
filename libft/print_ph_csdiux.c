/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ph_csdiux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 04:15:44 by schaisil          #+#    #+#             */
/*   Updated: 2022/07/14 07:13:36 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_ph_c(va_list *arglist, int *count)
{
	unsigned char	c;

	c = va_arg(*arglist, int);
	write(1, &c, 1);
	(*count)++;
}

void	print_ph_s(va_list *arglist, int *count)
{
	char	*s;
	int		len;

	s = va_arg(*arglist, char *);
	if (s != NULL)
	{
		len = ft_strlen(s);
		write(1, s, len);
		*count += len;
	}
	else
	{
		write(1, "(null)", 6);
		*count += 6;
	}
}

void	print_ph_d_i(va_list *arglist, int *count)
{
	int	n;

	n = va_arg(*arglist, int);
	ft_putnbr_fd(n, 1);
	*count += ft_lennbr(n);
}

void	print_ph_u(va_list *arglist, int *count)
{
	unsigned int	u;

	u = va_arg(*arglist, unsigned int);
	ft_putunbr_fd(u, 1);
	*count += ft_lenunbr(u);
}

void	print_ph_x(va_list *arglist, int *count)
{
	unsigned int	x;

	x = va_arg(*arglist, unsigned int);
	ft_puthex_fd(x, 1);
	*count += ft_lenhex(x);
}
