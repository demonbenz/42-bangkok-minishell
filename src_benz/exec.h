/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:36:52 by otangkab          #+#    #+#             */
/*   Updated: 2023/07/24 22:33:33 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# define TMP_FILE "temporary_file_fd_will_be_remove_after_used"

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <sys/stat.h>
# include "libft.h"
# include "../src/minishell.h"
# include "../src/bi_cmds.h"

typedef struct s_exec
{
	t_cmd				*arg;
	char				**envp;
	pid_t				pid;
	int					*all_pid;
	int					fd[2];
	int					index;
	int					*total_cmds;
	int					shell_input;
	int					*exit;
	int					*app_exit_num;
	int					*cmd_exit_num;
	struct stat			tmp_file_info;
	struct sigaction	*sa_i;
	struct sigaction	*sa_q;
	t_info				*info_ptr;
}t_exec;

// ms_executor.c
int		run_single_command(t_exec *exec, t_info *info);
void	init_exec(t_exec *exec, t_info *info);
int		ms_executor(t_list *cmds, t_info *extra);

// child_parent_process.c
void	parent_wait_command(t_exec *exec);
void	child_execution_command(t_exec *exec);
int		child_execution_step(t_exec *exec);

// read_infile_heredoc.c
int		check_infile_and_write(int fd_open, int tmp_fd);
int		read_infiles(char **infile_sym, int tmp_fd, t_exec *exec);
int		read_heredoc(char **heredoc_sym, int tmp_fd, t_exec *exec);
char	*in_here_doc(char **sym, char *delim, int index, t_exec *exec);

// redirection.c
int		redirect_input(t_exec *exec);
int		redirect_dup_output(t_exec *exec);
void	dup_input(int *fd);
int		dup_output(int fd_out);
void	handle_quit(int signum);
void	handle_interrupt(int signum);

// loop_open.c
int		loop_open_outfile(t_exec *exec);
int		loop_open_append(t_exec *exec);

// run_builtin.c
int		try_execute_child_buildin(t_exec *exec);
int		try_execute_quiet_buildin(t_exec *exec);

// run_execution.c
int		simple_execution(t_exec *exec);
int		join_path_then_execution(t_exec *exec);
void	open_quit_signal_on_valid_cmd(t_exec *exec);

// echo.c
void	echo_with_text(char **cmd, int first);
int		run_echo(t_exec *exec);

// cd.c
char	*get_var(char **envp, char *var);
void	update_old_new_pwd(t_exec *exec);
int		run_cd(t_exec *exec);

// export.c
void	sort_dubb_ptr(char **envp_dup);
char	*find_keyword(char *str, char c);
int		match_command(t_exec *exec, char *str);
void	run_export_no_arg(t_exec *exec);
void	run_export_with_arg(t_exec *exec);
int		check_export_arg(char *str);

// unset.c
void	run_unset(t_exec *exec);

//check_path.c
void	free_dubptr(char **ptr);
char	*joinpath(char *cmd, char *path);
char	**split_path(char **env);
char	*findpath(char *cmd, char **envp);
char	*check_path(char *cmd, char **envp);

// exit.c
void	run_exit(t_exec *exec);

// ex_util.c
int		is_include_char(char *str, char c);
int		print_error_msg(char *msg);
void	free_2_value(char *str1, char *str2);

#endif
