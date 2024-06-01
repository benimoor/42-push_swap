/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:32:28 by ergrigor          #+#    #+#             */
/*   Updated: 2022/11/19 23:32:40 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

#if defined(__APPLE__) && defined(__MACH__)
    #define MAX_OPEN_FILES OPEN_MAX
#elif defined(__linux__)
    #define MAX_OPEN_FILES FOPEN_MAX
#else
    #error "Unsupported OS"
#endif

typedef struct s_get_next_line	t_get_gnl_line;

struct s_get_next_line
{
	char	*buffer;
	char	*fd_buffer[MAX_OPEN_FILES];
};

char	*gnl_get_line(char *buffer);
char	*gnl_get_buffer(char *buffer);
int		get_next_line(int fd, char **line);
int		ft_gnl_strchr(const char *s, int c);
size_t	ft_gnl_strlen(const char *s1);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*get_gnl_line(char *memory);
char	*get_gnl_buffer(char *s);

#endif
