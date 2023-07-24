# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otangkab <otangkab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 18:05:53 by schaisil          #+#    #+#              #
#    Updated: 2023/07/24 14:14:33 by otangkab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
LIBFT	=	libft/libft.a

SRCS	=	main.c \
			ms_info.c \
			ms_prompt.c \
			ms_signal.c \
			ms_util.c \
			lstr_a.c lstr_b.c \
			draft_a.c draft_b.c \
			env_key.c \
			split_input.c \
			ms_lexer.c \
			ms_check_grammar.c \
			str_splice.c \
			ms_parser.c \
			ms_expander.c \
			ms_ctab_a.c \
			ms_ctab_b.c \
			ms_ctab_c.c \
			ms_pipe_cuts.c \
			bi_bcho.c \
			bi_env.c
SRCS_B	= 	ms_executor.c \
			check_path.c \
			export_a.c export_b.c \
			unset.c \
			cd.c \
			echo.c \
			run_execution.c \
			run_builtin.c \
			redirection.c \
			read_infile_heredoc.c \
			child_parent_process.c \
			exit.c \
			ex_utils.c \
			loop_open.c

FP_OBJS	=	$(SRCS:%.c=build/%.o)
FP_OBJS_B	=	$(SRCS_B:%.c=build_b/%.o)

READLINE_INC_PATH = -I/usr/local/opt/readline/include -I./libft/ -I./include/
READLINE_LIB_PATH = -L/usr/local/opt/readline/lib -lreadline -L./libft -lft

all: $(NAME)

$(NAME): $(LIBFT) $(FP_OBJS) $(FP_OBJS_B)
	cc -o $(NAME) $(FP_OBJS) $(FP_OBJS_B) $(READLINE_LIB_PATH) $(READLINE_INC_PATH)

$(LIBFT):
	@make -C libft

build/%.o: src/%.c
	@cc -o $@ -c $< $(READLINE_INC_PATH) -Wall -Wextra -Werror
build_b/%.o: src_benz/%.c
	@cc -o $@ -c $< $(READLINE_INC_PATH) -Wall -Wextra -Werror

p0:
	cc -o p0 p0.c $(READLINE_LIB_PATH) $(READLINE_INC_PATH)
# ----------------------------------------
.PHONY: all clean fclean re

clean:
	@rm -f $(FP_OBJS) $(FP_OBJS_B)
	@make clean -C libft

fclean:
	@rm -f $(FP_OBJS) $(FP_OBJS_B) $(NAME)
	@make fclean -C libft

re: fclean all
