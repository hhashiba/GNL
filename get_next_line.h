/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:22:56 by hhashiba          #+#    #+#             */
/*   Updated: 2022/06/07 17:22:58 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include	<stdlib.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	<stdbool.h>

typedef struct s_line
{
	char	*line;
	ssize_t	len;
}	t_line;

char	*get_next_line(int fd);
//utils
size_t	ft_strlen_chr(const char *str, int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strcpy_chr(char *dst, const char *src, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
