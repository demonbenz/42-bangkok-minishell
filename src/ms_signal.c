/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:17:13 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/16 13:17:04 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	handle_sigint_parent(int signum)
{
	if (signum == SIGINT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handle_sigint_child(int signum)
{
	if (signum == SIGINT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		exit(130);
	}
}

void	init_signal(t_info *info)
{
	ft_memset(&info->sa_i, 0, sizeof(struct sigaction));
	info->sa_i.sa_flags = SA_RESTART;
	set_signal(info, HANDLE_SIGINT_PARENT);
	ft_memset(&info->sa_q, 0, sizeof(struct sigaction));
	info->sa_q.sa_flags = SA_RESTART;
	set_signal(info, IGNORE_SIGQUIT);
}

void	set_signal(t_info *info, int type)
{
	if (type == HANDLE_SIGINT_PARENT)
	{
		info->sa_i.sa_handler = handle_sigint_parent;
		sigaction(SIGINT, &info->sa_i, NULL);
	}
	else if (type == IGNORE_SIGINT_PARENT)
	{
		info->sa_i.sa_handler = SIG_IGN;
		sigaction(SIGINT, &info->sa_i, NULL);
	}
	else if (type == IGNORE_SIGQUIT)
	{
		info->sa_q.sa_handler = SIG_IGN;
		sigaction(SIGQUIT, &info->sa_q, NULL);
	}
}

void	set_echo_ctl(int b_enable)
{
	struct termios	terminal;

	tcgetattr(STDIN_FILENO, &terminal);
	if (b_enable)
		terminal.c_lflag |= ECHOCTL;
	else
		terminal.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &terminal);
}
