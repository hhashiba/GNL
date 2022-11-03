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

static ssize_t	check_fd(t_line *save, int fd)
{
	ssize_t	i;

	i = 0;
	while (i < FOPEN_MAX)
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

	buf = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
	{
		free(save->line);
		return (NULL);
	}
	save->len = read(fd, buf, BUFFER_SIZE);
	if (save->len == -1)
	{
		free(buf);
		free(save->line);
		return (NULL);
	}
	buf[save->len] = '\0';
	save->line = ft_strjoin(save->line, buf);
	free(buf);
	if (save->line == NULL)
		return (NULL);
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
	{
		free(save->line);
		return (NULL);
	}
	line = ft_strcpy_chr(line, save->line, '\n');
	tmp = ft_strjoin(NULL, &save->line[rtn_len + 1]);
	free(save->line);
	if (tmp == NULL)
	{
		free(line);
		return (NULL);
	}
	save->line = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	ssize_t			i;
	static t_line	save[FOPEN_MAX];

	i = check_fd(save, fd);
	if (fd < 0 || BUFFER_SIZE <= 0 || i == -1)
		return (NULL);
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
	{
		free(save[i].line);
		return (NULL);
	}
	return (save[i].line);
}
