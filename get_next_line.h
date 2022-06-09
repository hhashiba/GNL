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
#  define BUFFER_SIZE 1000
# endif

# include	<stdlib.h>
# include	<fcntl.h>
# include	<unistd.h>

typedef struct s_line
{
	char			*line;
	ssize_t			len;
}	t_line;

// #include	"../leaks_identify/leaks_identify.h"
// #define init leaks_identify_init
// #define malloc(s) leaks_identify_malloc(s, __FILE__, __LINE__)
// #define free leaks_identify_free
// #define check leaks_identify_check

char	*get_next_line(int fd);
char	*free_rtn(char *ptr);

size_t	ft_strlen_chr(const char *str, int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strcpy_chr(char *dst, const char *src, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
