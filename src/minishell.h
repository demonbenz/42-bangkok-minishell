/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:08:13 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/24 21:52:38 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>

# include "libft.h"
# include "lstr.h"

# define DISABLE 0
# define ENABLE 1
# define TOTAL_CMDS_SUPPORTED 4
# define HANDLE_SIGINT_PARENT 1
# define IGNORE_SIGINT_PARENT 2
# define IGNORE_SIGQUIT 3

# define ERR_MEM "Error, cannot allocate memory!\n"
# define ERR_LEX0 "lexer: detect unsupported opt, "
# define ERR_LEX1 "lexer: unable to detect ending quote, "
# define ERR_LEX2 "lexer: syntax error near unexpected token\n"
# define ERR_LEX3 "lexer: detect too many cmds, allowed max of 3 pipes\n"

typedef struct s_info	t_info;
struct s_info
{
	char				**envs;
	int					exit;
	int					app_exit_num;
	int					cmd_exit_num;
	int					total_cmds;
	struct sigaction	sa_i;
	struct sigaction	sa_q;
	char				*parse_in;
	char				*parse_out;
};

typedef struct s_cmd	t_cmd;
struct s_cmd
{
	char	**cmd;
	char	**infile_sym;
	char	**outfile_sym;
	char	**heredoc_sym;
	char	**append_sym;
	int		last_in;
	int		last_out;
};

// prototypes:
void	ms_init(t_info *info, char **envs);
void	print_welcome_text(void);
void	init_signal(t_info *info);
void	set_signal(t_info *info, int type);
void	handle_sigint_parent(int sig);
void	handle_sigint_child(int signum);
void	set_echo_ctl(int b_enable);

int		ms_prompt_loop(t_info *info);

void	ms_clear(t_info *info);
void	free_info(t_info *info);

// util
int		is_empty_input(char *str);
int		is_whitespace(char c);
int		is_argv_contains_empty_arg(int argc, char **argv);
int		is_empty_arg(char *str);
t_list	*split_ex(char *line);
t_lstr	*split_input(char *trim_line);
int		len_word(char *str);
int		len_quote(char *str);

void	print_list(t_list *l);
int		add_first_word_to_list(t_lstr **words_rf, char *str);
char	*create_value_from_env_key(char *key, char **envs);
int		get_last_zq_index(char *str);
char	*create_first_env_key(char *str);

// draft2:
int		ms_check_grammar(t_lstr *words);
int		is_unsupported_opt(char *str);
int		is_unpaired_quote(char *str);
void	skip_to_ending_quote(char *str, int *i);
int		is_opt_with_invalid_arg(char *opt, char *opt_arg);
int		is_opt(char *str);

char	*strdup_big(const char *s1, int bytes);
char	*str_splice(char *str, int start, int del_count);

t_lstr	*ms_lexer(char *trim_line);

void	ms_parser(t_lstr *words, t_info *info);
void	parse_word(t_lstr *words, t_info *info);
void	dequote_sq(t_info *info, int *i, int *j);
void	dequote_dq(t_info *info, int *i, int *j);
int		len_word_in_quote(char *str);

int		is_expand_home(char *word, t_info *info);
void	expand_var(t_info *info, int *i, int *j);

void	ms_clean_loop(char *str, t_lstr **lst_rf);
void	free_split(char **strs);

// cmd_table
int		count_pipe(t_lstr *words);
void	free_lcmds(t_lstr **lcmds, int total_cmds);
void	print_lcmds(t_lstr **lcmds, int total_cmds);

// refactor
t_lstr	**pipe_cuts(t_lstr *words, t_info *info);
void	cuts_map_head(t_lstr **lcmds, t_lstr *words);
void	cuts_trim(t_lstr **lcmds);

void	free_ctabs(t_cmd **ctabs, int total_cmds);
void	lstr_remove_two(t_lstr **lst_rf, t_lstr *prev);
void	print_options(char **strs);
void	print_ctabs(t_cmd **ctabs, int total_cmds);

// ctabs
t_cmd	**create_cmd_table(t_lstr **lcmds, int total_cmds);
char	**extract_options(t_lstr **lst_rf, char *opt);
void	allocate_options(char ***result, t_lstr *lst, char *opt);
int		count_options(t_lstr *lst, char *opt);
void	extract_opt(char **result, t_lstr **lst, int *i, t_lstr *prev);

t_cmd	**create_command_table(char *line, t_info *info);
void	create_cmd_table_part2(t_cmd **ctabs, t_lstr **lcmds, int total_cmds);
void	create_cmd_table_part3(t_cmd **ctabs, t_lstr **lcmds, int total_cmds);
char	**extract_cmd(t_lstr **lstr_rf);
void	free_ctabs(t_cmd **ctabs, int total_cmds);
void	free_ctab(void *content);
t_list	*create_list_ctabs(t_cmd **ctabs, int total_cmds);
void	free_command_table(t_list **list_ctabs, t_cmd **ctabs, int total_cmds);

char	**strs_dup(char **strs);
int		ms_executor(t_list *cmd_tab, t_info *info);

#endif
