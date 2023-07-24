# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 19:43:34 by schaisil          #+#    #+#              #
#    Updated: 2023/03/20 17:28:32 by schaisil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a
OBJS =	ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
		ft_toupper.o ft_tolower.o \
		ft_strlen.o \
		ft_strchr.o ft_strrchr.o ft_memchr.o ft_strnstr.o \
		ft_strncmp.o ft_memcmp.o \
		ft_strlcpy.o ft_strlcat.o \
		ft_bzero.o ft_memset.o ft_memcpy.o ft_memmove.o \
		ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o \
		ft_calloc.o ft_strdup.o \
		ft_atoi.o \
		ft_putnbr_fd.o ft_itoa.o \
		ft_strtrim.o ft_substr.o \
		ft_strjoin.o ft_split.o \
		ft_striteri.o ft_strmapi.o \
		ft_lstnew.o ft_lstadd_front.o \
		ft_lstsize.o ft_lstlast.o \
		ft_lstadd_back.o \
		ft_lstdelone.o ft_lstclear.o \
		ft_lstiter.o ft_lstmap.o \
		ft_putunbr_fd.o ft_puthex_fd.o ft_puthexupper_fd.o ft_putllhex_fd.o \
		ft_lennbr.o ft_lenunbr.o ft_lenhex.o ft_lenllhex.o \
		ft_printf.o print_ph_csdiux.o print_ph_upper_x_p.o \
		ft_isequalstrn.o \
		get_next_line.o get_next_line_utils.o \
		ps_atoi.o \
		is_str_number.o is_str_inbound.o is_str_integer.o

FP_OBJS =	$(OBJS:%.o=build/%.o)

all: $(NAME)

$(NAME): $(FP_OBJS)
	@ar -rcs $(NAME) $(FP_OBJS)

build/%.o: %.c
	@gcc -o $@ -c $< -Wall -Wextra -Werror

.PHONY: all clean fclean re

clean:
	@rm -f $(FP_OBJS)

fclean:
	@rm -f $(FP_OBJS) $(NAME)

re: fclean all
