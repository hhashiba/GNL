/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:39:56 by hhashiba          #+#    #+#             */
/*   Updated: 2022/06/10 14:39:57 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line_bonus.h"

static char	*free_rtn(char *ptr1, char *ptr2)
{
	free(ptr1);
	free(ptr2);
	return (NULL);
}

static ssize_t	check_fd(t_line *save, int fd)
{
	ssize_t	i;

	i = 0;
	while (i + 1 < FOPEN_MAX)
	{
		if (save[i].fd == fd)
			return (i);
		if (save[i].fd == 0)
		{
			save[i].fd = fd;
			return (i);
		}
		i++;
	}
	return (-1);
}

static bool	read_file(t_line *save, int fd)
{
	char	*buf;

	buf = malloc((size_t)(BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (free_rtn(save->line, NULL));
	save->len = read(fd, buf, BUFFER_SIZE);
	if (save->len == -1)
		return (free_rtn(buf, save->line));
	buf[save->len] = '\0';
	save->line = ft_strjoin(save->line, buf);
	if (save->line == NULL)
		return (free_rtn(buf, NULL));
	free(buf);
	return (true);
}

static char	*get_line(t_line *save)
{
	size_t	rtn_len;
	char	*line;
	char	*tmp;

	rtn_len = ft_strlen_chr(save->line, '\n');
	line = malloc((rtn_len + 2) * sizeof(char));
	if (line == NULL)
		return (free_rtn(save->line, NULL));
	line = ft_strcpy_chr(line, save->line, '\n');
	tmp = ft_strjoin(NULL, &save->line[rtn_len + 1]);
	free(save->line);
	if (tmp == NULL)
		return (free_rtn(line, NULL));
	save->line = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	ssize_t			i;
	static t_line	save[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = check_fd(save, fd);
	if (save[i].len == -1)
		save[i].line = NULL;
	save[i].len = 1;
	while (save[i].len != 0)
	{
		if (read_file(&save[i], fd) == false)
			return (NULL);
		if (ft_strchr(save[i].line, '\n') != NULL)
			return (get_line(&save[i]));
	}
	save[i].len = -1;
	if (save[i].line[0] == '\0')
		return (free_rtn(save[i].line, NULL));
	return (save[i].line);
}
