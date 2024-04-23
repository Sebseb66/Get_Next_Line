/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfroidev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:52:23 by sfroidev          #+#    #+#             */
/*   Updated: 2023/03/13 13:58:35 by sfroidev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strdup(char *str, size_t i);
char	*ft_check(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
