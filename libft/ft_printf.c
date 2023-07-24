/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:26:47 by schaisil          #+#    #+#             */
/*   Updated: 2023/03/01 20:49:33 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_by_placeholder(char ph, va_list *arglist, int *count)
{
	if (ph == '%')
	{
		ft_putchar_fd('%', 1);
		*count += 1;
	}
	else if (ph == 'c')
		print_ph_c(arglist, count);
	else if (ph == 's')
		print_ph_s(arglist, count);
	else if (ph == 'd' || ph == 'i')
		print_ph_d_i(arglist, count);
	else if (ph == 'u')
		print_ph_u(arglist, count);
	else if (ph == 'x')
		print_ph_x(arglist, count);
	else if (ph == 'X')
		print_ph_upper_x(arglist, count);
	else if (ph == 'p')
		print_ph_p(arglist, count);
	else if (ph == 'o')
		print_ph_o(arglist, count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arglist;
	int		count;
	int		i;

	va_start(arglist, str);
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			count++;
			i++;
		}
		else
		{
			print_by_placeholder(str[i + 1], &arglist, &count);
			i += 2;
		}
	}
	va_end(arglist);
	return (count);
}
