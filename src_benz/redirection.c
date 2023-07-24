/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:46:40 by otangkab          #+#    #+#             */
/*   Updated: 2023/07/24 22:34:24 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	err_msg_condition(int mode, t_exec *exec)
{
	if (mode == 1)
	{
		print_error_msg(exec->arg->infile_sym[0]);
		return (-1);
	}
	else if (mode == 2)
	{
		print_error_msg(exec->arg->heredoc_sym[0]);
		return (-1);
	}
	return (0);
}

int	redirect_input(t_exec *exec)
{
	int	tmp_fd;
	int	err_mode;

	if (exec->arg->heredoc_sym[0] != NULL)
	{
		exec->sa_i->sa_handler = handle_interrupt;
		sigaction(SIGINT, exec->sa_i, NULL);
	}
	err_mode = 0;
	if (exec->arg->infile_sym[0] == NULL && exec->arg->heredoc_sym[0] == NULL)
		return (0);
	tmp_fd = open(TMP_FILE, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (tmp_fd < 0)
	{
		print_error_msg(TMP_FILE);
		return (-1);
	}
	if (read_infiles(exec->arg->infile_sym, tmp_fd, exec) < 0)
		err_mode = 1;
	if (read_heredoc(exec->arg->heredoc_sym, tmp_fd, exec) < 0)
		err_mode = 2;
	if (err_msg_condition(err_mode, exec) < 0)
		return (-1);
	close(tmp_fd);
	return (0);
}

void	dup_input(int *fd)
{
	int	tmp_fd;

	tmp_fd = open(TMP_FILE, O_RDONLY);
	if (tmp_fd < 0)
	{
		close(fd[0]);
		return ;
	}
	dup2(tmp_fd, 0);
	close(tmp_fd);
	close(fd[0]);
	return ;
}

int	dup_output(int fd_out)
{
	if (fd_out < 0)
		return (-1);
	else if (fd_out > 2)
	{
		dup2(fd_out, 1);
		close(fd_out);
	}
	return (0);
}

int	redirect_dup_output(t_exec *exec)
{
	int	fd_out;
	int	out;
	int	appn;

	fd_out = 0;
	out = 0;
	appn = 0;
	if ((exec->arg->outfile_sym[0] == NULL) \
			&& (exec->arg->append_sym[0] == NULL) \
			&& (exec->index < (*exec->total_cmds - 1)))
		dup2(exec->fd[1], 1);
	else
	{
		if (exec->arg->outfile_sym[0] != NULL)
			out = loop_open_outfile(exec);
		if (exec->arg->append_sym[0] != NULL)
			appn = loop_open_append(exec);
	}
	fd_out = out;
	if (exec->arg->last_out == 4)
		fd_out = appn;
	if (dup_output(fd_out) < 0)
		return (-1);
	close(exec->fd[1]);
	return (0);
}
// int	redirect_input(t_exec *exec)
// {
// 	int	tmp_fd;
// 	int	err;

// 	err = 0;
// 	if (exec->arg->infile_sym[0] == NULL && exec->arg->heredoc_sym[0] == NULL)
// 		return (0);
// 	tmp_fd = open(TMP_FILE, O_RDWR | O_CREAT | O_APPEND, 0644);
// 	if (tmp_fd < 0)
// 	{
// 		print_error_msg(TMP_FILE);
// 		return (-1);
// 	}
// 	if (read_infiles(exec->arg->infile_sym, tmp_fd, exec) < 0)
// 	{
// 		print_error_msg(exec->arg->infile_sym[0]);
// 		return (-1);
// 	}
// 	if (read_heredoc(exec->arg->heredoc_sym, tmp_fd, exec) < 0)
// 	{
// 		print_error_msg(exec->arg->heredoc_sym[0]);
// 		return (-1);
// 	}
// 	close(tmp_fd);
// 	return (0);
// }

// int	redirect_input(t_exec *exec)
// {
// 	int	tmp_fd;
// 	int	err_mode;

// 	err_mode = 0;
// 	if (exec->arg->infile_sym[0] == NULL && exec->arg->heredoc_sym[0] == NULL)
// 		return (0);
// 	tmp_fd = open(TMP_FILE, O_RDWR | O_CREAT | O_APPEND, 0644);
// 	if (tmp_fd < 0)
// 	{
// 		print_error_msg(TMP_FILE);
// 		return (-1);
// 	}
// 	if (read_infiles(exec->arg->infile_sym, tmp_fd, exec) < 0)
// 		err_mode = 1;
// 	if (read_heredoc(exec->arg->heredoc_sym, tmp_fd, exec) < 0)
// 		err_mode = 2;
// 	if (err_msg_condition(err_mode, exec) < 0)
// 		return (-1);
// 	if (err_mode == 1)
// 	{
// 		print_error_msg(exec->arg->infile_sym[0]);
// 		return (-1);
// 	}
// 	else if (err_mode == 2)
// 	{
// 		print_error_msg(exec->arg->heredoc_sym[0]);
// 		return (-1);
// 	}
// 	close(tmp_fd);
// 	return (0);
// }
