/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfroidev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:51:43 by sfroidev          #+#    #+#             */
/*   Updated: 2023/03/24 09:35:04 by sfroidev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_read_line(int fd, char *str)
{
	char	*buf;
	int		r;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	r = 1;
	while (r != 0 && !ft_check(str, '\n'))
	{
		r = read(fd, buf, BUFFER_SIZE);
		buf[r] = '\0';
		if (buf)
			str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

static char	*ft_check_line(char *str)
{
	char		*res;
	int			len;
	int			i;

	if (!str || !str[0])
		return (NULL);
	i = 0;
	len = 0 ;
	while (str[len] && str[len] != '\n')
		len ++;
	if (str[len] == '\n')
		len ++;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = str [i];
		i ++;
	}
	res[i] = 0;
	return (res);
}

static char	*ft_clean_line(char *str, size_t i)
{
	char	*rest;

	rest = NULL;
	if (!str[i])
	{
		free(str);
		return (rest);
	}
	if (str[i])
		rest = ft_strdup(str, i);
	free (str);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*buf = NULL;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = ft_read_line(fd, buf);
	res = ft_check_line(buf);
	if (buf)
		buf = ft_clean_line(buf, ft_strlen(res));
	return (res);
}
