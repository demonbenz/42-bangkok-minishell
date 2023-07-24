/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaisil <schaisil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 03:06:18 by schaisil          #+#    #+#             */
/*   Updated: 2023/07/16 15:10:06 by schaisil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// note: allocate new q, join s to q from back, free old q
//       support NULL input
// return: new q, or NULL if unable to malloc
char	*bq_push_str(char *q, char *s)
{
	char	*result;

	if (s == NULL)
		return (q);
	if (q == NULL)
		return (u_strjoin("", s));
	else
	{
		result = u_strjoin(q, s);
		free(q);
		return (result);
	}
}

// note: free allocated memory, to prevent leak from "rare" case of error,
//       that occur in the middle of multiple read calls (due to result has
//       already acquired some text prior to read-error event)
char	*free_on_error(char *s, int bytes_read)
{
	if (bytes_read == -1)
	{
		if (s != NULL)
			free(s);
		s = NULL;
	}
	return (s);
}

// note: read from file descriptor, until '\n' is found or EoF
// return: one line of str, including bytes after '\n' when bytes till '\n'
//         is not equal to buffer_size
//         return NULL when unable to malloc, read error occur, or read at EoF
char	*read_endl(int fd, int buffer_size)
{
	char	*result;
	char	*buf;
	int		bytes_read;

	if (buffer_size == 0)
		buffer_size = BUFFER_SIZE;
	result = NULL;
	buf = (char *) malloc((buffer_size + 1) * sizeof (char));
	if (buf != NULL)
	{
		buf[0] = '\0';
		bytes_read = 1;
		while (!has_endl(buf) && bytes_read > 0)
		{
			bytes_read = read(fd, buf, buffer_size);
			if (bytes_read > 0)
			{
				buf[bytes_read] = '\0';
				result = bq_push_str(result, buf);
			}
		}
		free(buf);
		free_on_error(result, bytes_read);
	}
	return (result);
}

// note: pop one line of text from input buffer queue,
// return: allocated str contain one line of text,
//         return NULL if unable to malloc or bq is empty_str/NULL
char	*bq_pop_endl(char *bq)
{
	int		len_result;
	char	*result;
	int		i;

	if (bq == NULL || bq[0] == '\0')
		return (NULL);
	len_result = len_endl(bq);
	result = (char *) malloc((len_result + 1) * sizeof(char));
	if (result != NULL)
	{
		result[0] = '\0';
		i = -1;
		while (++i < len_result)
			result[i] = bq[i];
		result[i] = '\0';
		while (bq[i] != '\0')
		{
			bq[i - len_result] = bq[i];
			i++;
		}
		bq[i - len_result] = '\0';
	}
	return (result);
}

// note: repeating read from file descriptor, until '\n' is found or EoF,
//       the read operation will read n=buffer_size characters per cycle,
//       and store reading characters into static buffer_queue,
//       then return result by poping one line from the buffer_queue
//       poping involve allocate new str, copy 1 line, and update buffer_queue
char	*get_next_line(int fd)
{
	static char	*buffer_queue[1024];
	char		*result;
	char		*temp;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer_queue[fd] == NULL)
	{
		buffer_queue[fd] = read_endl(fd, BUFFER_SIZE);
	}
	else if (!has_endl(buffer_queue[fd]))
	{
		temp = read_endl(fd, BUFFER_SIZE);
		buffer_queue[fd] = bq_push_str(buffer_queue[fd], temp);
		if (temp != NULL)
			free(temp);
	}
	result = bq_pop_endl(buffer_queue[fd]);
	if (result == NULL)
	{
		if (buffer_queue[fd] != NULL)
			free(buffer_queue[fd]);
		buffer_queue[fd] = NULL;
	}
	return (result);
}

// log 01: may put above if (bytes_read > 0) [~line 69], to observe read calls
// printf("[read: %d, with buffer_size %d]\n", bytes_read, buffer_size);

// log 02: may put above return [~line 142], to observe buffer_queue
// printf("[fd: %d, bq: %s]\n", fd, buffer_queue[fd]);
