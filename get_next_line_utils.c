/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:22:44 by hhashiba          #+#    #+#             */
/*   Updated: 2022/06/07 17:22:45 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

size_t	ft_strlen_chr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != (char)c)
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	ch;

	ch = c;
	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == ch)
			break ;
		str++;
	}
	if (ch == '\0' || *str != '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strcpy_chr(char *dst, const char *src, int c)
{
	size_t	i;
	char	ch;

	i = 0;
	ch = c;
	while (src[i] != '\0' && src[i] != ch)
	{
		dst[i] = src[i];
		i++;
	}
	if (ch != '\0')
		dst[i++] = ch;
	dst[i] = '\0';
	return (dst);
}

char	*ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen_chr(dst, '\0');
	while (src[i] != '\0')
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	len;

	if (s1 == NULL)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen_chr(s1, '\0') + ft_strlen_chr(s2, '\0');
	s3 = malloc((len + 1) * sizeof(char));
	if (s3 == NULL)
		return (free_rtn(s1));
	s3 = ft_strcpy_chr(s3, s1, '\0');
	s3 = ft_strcat(s3, s2);
	free(s1);
	return (s3);
}
