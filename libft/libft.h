/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:30:13 by schaisil          #+#    #+#             */
/*   Updated: 2023/03/20 17:33:21 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdarg.h>

# ifdef __linux__
#  define IS_COMPILE_LINUX 1
# else
#  define IS_COMPILE_LINUX 0
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// mandatory prototypes
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// bonus prototypes
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// ft_printf additional prototypes
void	ft_putunbr_fd(unsigned int n, int fd);
void	ft_putllhex_fd(unsigned long long n, int fd);
void	ft_puthex_fd(unsigned int n, int fd);
void	ft_puthexupper_fd(unsigned int n, int fd);
int		ft_lennbr(int n);
int		ft_lenunbr(unsigned int n);
int		ft_lenhex(unsigned int n);
int		ft_lenllhex(unsigned long long n);
int		ft_printf(const char *str, ...);
void	print_ph_c(va_list *arglist, int *count);
void	print_ph_s(va_list *arglist, int *count);
void	print_ph_d_i(va_list *arglist, int *count);
void	print_ph_u(va_list *arglist, int *count);
void	print_ph_x(va_list *arglist, int *count);
void	print_ph_upper_x(va_list *arglist, int *count);
void	print_ph_p(va_list *arglist, int *count);
void	print_ph_o(va_list *arglist, int *count);
void	print_by_placeholder(char ph, va_list *arglist, int *count);

// get_next_line additional prototypes
int		ft_isequalstrn(const char *s1, const char *s2, size_t n);
size_t	u_strlen(const char *s);
char	*u_strjoin(char const *s1, char const *s2);
int		has_endl(char *s);
int		len_endl(const char *s);
char	*bq_push_str(char *q, char *s);
char	*read_endl(int fd, int buffer_size);
char	*bq_pop_endl(char *bq);
char	*get_next_line(int fd);

// push_swap additional prototypes
int		ps_atoi(char *str);
int		is_str_integer(char *str);
int		is_str_number(char *str);
int		is_str_inbound(char *str);

#endif
