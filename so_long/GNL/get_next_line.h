/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:28:29 by sgo               #+#    #+#             */
/*   Updated: 2023/08/11 16:37:32 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read_line(int fd, char *buf, char *line, char *backup);
char	*check_backup(char *backup, size_t len);

char	*ft_strjoin(char *s1, char *s2, size_t len_s2);
int		get_strlen(const char *str);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*freestr(char *str);
void	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *s1);
void	ft_putstr_fd(char *s);

#endif