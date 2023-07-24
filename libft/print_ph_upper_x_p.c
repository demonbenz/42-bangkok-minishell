/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ph_upper_x_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 07:14:50 by schaisil          #+#    #+#             */
/*   Updated: 2023/03/07 13:56:43 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_ph_upper_x(va_list *arglist, int *count)
{
	unsigned int	x;

	x = va_arg(*arglist, unsigned int);
	ft_puthexupper_fd(x, 1);
	*count += ft_lenhex(x);
}

void	print_ph_p(va_list *arglist, int *count)
{
	unsigned long long	ull;

	ull = (unsigned long long) va_arg(*arglist, void *);
	if (ull == 0 && IS_COMPILE_LINUX)
	{
		ft_putstr_fd("(nil)", 1);
		*count += 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		*count += 2;
		ft_putllhex_fd(ull, 1);
		*count += ft_lenllhex(ull);
	}
}

void	print_ph_o(va_list *arglist, int *count)
{
	unsigned long long	ull;

	ull = (unsigned long long) va_arg(*arglist, void *);
	if (ull == 0 && IS_COMPILE_LINUX)
	{
		ft_putstr_fd("(nil)", 1);
		*count += 5;
	}
	else
	{
		ull = ull % (16 * 16 * 16 * 16 * 16 * 16);
		ft_putstr_fd("0x", 1);
		*count += 2;
		ft_putllhex_fd(ull, 1);
		*count += ft_lenllhex(ull);
	}
}
