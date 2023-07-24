/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <otangkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:12:58 by otangkab          #+#    #+#             */
/*   Updated: 2023/07/24 14:17:13 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	loop_open_outfile(t_exec *exec)
{
	int	i;
	int	fd_out;

	i = 0;
	while (exec->arg->outfile_sym[i] != NULL)
	{
		fd_out = open(exec->arg->outfile_sym[i++], \
		O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	if (fd_out < 0)
	{
		print_error_msg(exec->arg->outfile_sym[0]);
		return (-1);
	}
	return (fd_out);
}

int	loop_open_append(t_exec *exec)
{
	int	i;
	int	fd_out;

	i = 0;
	while (exec->arg->append_sym[i] != NULL)
	{
		fd_out = open(exec->arg->append_sym[i++], \
		O_CREAT | O_RDWR | O_APPEND, 0644);
	}
	if (fd_out < 0)
	{
		print_error_msg(exec->arg->append_sym[0]);
		return (-1);
	}
	return (fd_out);
}
