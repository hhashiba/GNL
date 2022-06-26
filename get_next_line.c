/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:22:29 by hhashiba          #+#    #+#             */
/*   Updated: 2022/06/07 17:22:31 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

static char	*free_rtn(char *ptr1, char *ptr2)
{
	free(ptr1);
	free(ptr2);
	return (NULL);
}

static bool	read_file(t_line *save, int fd)
{
	char	*buf;

	buf = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
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
	static t_line	save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (save.len == -1)
		save.line = NULL;
	save.len = 1;
	while (save.len != 0)
	{
		if (read_file(&save, fd) == false)
			return (NULL);
		if (ft_strchr(save.line, '\n') != NULL)
			return (get_line(&save));
	}
	save.len = -1;
	if (save.line[0] == '\0')
		return (free_rtn(save.line, NULL));
	return (save.line);
}
