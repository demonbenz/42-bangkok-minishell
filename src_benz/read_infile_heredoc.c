/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_infile_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <otangkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:04:36 by otangkab          #+#    #+#             */
/*   Updated: 2023/07/24 13:29:17 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	check_infile_and_write(int fd_open, int tmp_fd)
{
	char	*buffer;
	int		ret;

	buffer = (char *)ft_calloc(sizeof(char), 10000);
	if (!buffer)
		return (-1);
	while (1)
	{
		ret = read(fd_open, buffer, 9999);
		if (ret <= 0)
			break ;
		ft_putstr_fd(buffer, tmp_fd);
	}
	free(buffer);
	return (0);
}

int	read_infiles(char **infile_sym, int tmp_fd, t_exec *exec)
{
	int		fd_open;
	int		i;

	if (!infile_sym)
		return (0);
	i = -1;
	while (infile_sym[++i] != NULL)
	{
		fd_open = open(infile_sym[i], O_RDONLY);
		if (fd_open < 0)
		{
			return (-1);
		}
		if (infile_sym[i + 1] == NULL && exec->arg->last_in == 1)
		{
			if (check_infile_and_write(fd_open, tmp_fd) < 0)
				return (-1);
		}
		close(fd_open);
	}
	return (0);
}

char	*in_here_doc(char **sym, char *delim, int index, t_exec *exec)
{
	char	*word_joined;
	char	*tmp_word;
	char	*word;
	int		ret;

	word = (char *)ft_calloc(10000, sizeof(char));
	word_joined = (char *)ft_calloc(1, sizeof(char));
	if (!word_joined || !word)
		return (0);
	while (1)
	{
		write(1, "> ", 2);
		ret = read(0, word, 10000);
		word[ret] = '\0';
		if (ft_strncmp(word, delim, ft_strlen(delim)) == 0 || word[0] == '\0')
			break ;
		if (sym[index + 1] == NULL && exec->arg->last_in == 2)
		{
			tmp_word = ft_strjoin(word_joined, word);
			free(word_joined);
			word_joined = tmp_word;
		}
	}
	free(word);
	return (word_joined);
}

int	read_heredoc(char **heredoc_sym, int tmp_fd, t_exec *exec)
{
	char	*word_joined;
	char	*delim;
	int		i;

	if (heredoc_sym[0] != NULL)
	{
		i = -1;
		while (heredoc_sym[++i] != NULL)
		{
			delim = ft_strjoin(heredoc_sym[i], "\n");
			word_joined = in_here_doc(heredoc_sym, delim, i, exec);
			if (!word_joined)
			{
				free(delim);
				return (-1);
			}
			free(delim);
			delim = NULL;
			write(tmp_fd, word_joined, ft_strlen(word_joined));
			free(word_joined);
		}
	}
	close(tmp_fd);
	return (0);
}

// int	read_heredoc(char **heredoc_sym, int tmp_fd)
// {
// 	char	*word;
// 	char	*word_joined;
// 	char	*delim;
// 	char	*tmp_word;
// 	int		key_len;
// 	int		ret;
// 	int		i;

// 	if (heredoc_sym[0] == NULL)
// 	{
// 		close(tmp_fd);
// 		return (0);
// 	}
// 	word = (char *)ft_calloc(10000, sizeof(char));
// 	if (!word)
// 		return (-1);
// 	i = 0;
// 		while (heredoc_sym[i] != NULL)
// 		{
// 			delim = ft_strjoin(heredoc_sym[i], "\n");
// 			key_len = ft_strlen(delim);
// 			word_joined = (char *)ft_calloc(1, sizeof(char));
// 			while (1)
// 			{
// 				write(1, "> ", 2);
// 				ret = read(0, word, 10000);
// 				word[ret] = '\0';
// 				if (ft_strncmp(word, delim, key_len) == 0 || word[0] == '\0')
// 					break ;
// 				if (heredoc_sym[i + 1] == NULL)
// 				{
// 					tmp_word = ft_strjoin(word_joined, word);
// 					free(word_joined);
// 					word_joined = tmp_word;
// 				}
// 			}
// 			free(delim);
// 			delim = NULL;
// 			write(tmp_fd, word_joined, ft_strlen(word_joined));
// 			free(word_joined);
// 			i++;
// 		}
// 	free(word);
// 	close(tmp_fd);
// 	return (0);
// }

// int	read_infiles(char **infile_sym, int tmp_fd, t_exec *exec)
// {
// 	char	*buffer;
// 	int		fd_open;
// 	int		word;
// 	int		i;

// 	if (!infile_sym)
// 		return (0);
// 	buffer = (char *)ft_calloc(sizeof(char), 1000);
// 	i = -1;
// 	while (infile_sym[++i] != NULL)
// 	{
// 		fd_open = open(infile_sym[i], O_RDONLY);
// 		if (fd_open < 0)
// 		{
// 			free(buffer);
// 			return (-1);
// 		}
// 		if (infile_sym[i + 1] == NULL && exec->arg->last_in == 1)
// 		{
// 			while (1)
// 			{
// 				word = read(fd_open, buffer, 999);
// 				if (word <= 0)
// 					break ;
// 				ft_putstr_fd(buffer, tmp_fd);
// 			}
// 		}
// 		close(fd_open);
// 	}
// 	free(buffer);
// 	return (0);
// }