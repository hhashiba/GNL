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

char	*free_rtn(char *ptr)
{
	free(ptr);
	return (NULL);
}

char	*read_file(t_line *save, char *buf, int fd)
{
	save->len = read(fd, buf, BUFFER_SIZE);
	if (save->len == -1)
		return (free_rtn(buf));
	buf[save->len] = '\0';
	save->line = ft_strjoin(save->line, buf);
	if (save->line == NULL)
		return (free_rtn(buf));
	return (buf);
}

char	*get_line(t_line *save)
{
	size_t	rtn_len;
	char	*line;
	char	*tmp;

	rtn_len = ft_strlen_chr(save->line, '\n');
	line = malloc((rtn_len + 1) * sizeof(char));
	if (line == NULL)
		return (free_rtn(save->line));
	line = ft_strcpy_chr(line, save->line, '\n');
	tmp = ft_strjoin(NULL, &save->line[rtn_len + 1]);
	free(save->line);
	if (tmp == NULL)
		return (free_rtn(line));
	save->line = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	char			*buf;
	static t_line	save;

	if (fd < 0 || BUFFER_SIZE <= 0 || save.len == -1)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	save.len = 1;
	while (save.len != 0)
	{
		buf = read_file(&save, buf, fd);
		if (buf == NULL)
			return (NULL);
		if (ft_strchr(save.line, '\n') != NULL)
		{
			free(buf);
			return (get_line(&save));
		}
	}
	free (buf);
	save.len = -1;
	if (save.line[0] == '\0')
		return (free_rtn(save.line));
	return (save.line);
}
