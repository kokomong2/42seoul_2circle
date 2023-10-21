/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:28:04 by sgo               #+#    #+#             */
/*   Updated: 2023/09/20 20:42:58 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	backup[BUFFER_SIZE + 1];
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	i = get_strlen(backup);
	line = check_backup(backup, i);
	if (!line)
		return (0);
	buf = (char *)malloc((BUFFER_SIZE + 1));
	if (!buf)
		return (freestr(line));
	if (line[0] == '\0' || line[i - 1] != '\n')
		line = ft_read_line(fd, buf, line, backup);
	freestr(buf);
	if (!line)
	{
		*backup = 0;
		return (0);
	}
	return (line);
}

char	*ft_read_line(int fd, char *buf, char *line, char *backup)
{
	char	*res;
	int		len;

	len = 1;
	res = line;
	buf[len - 1] = 0;
	while (buf[len - 1] != '\n')
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < 0 || (len == 0 && *res == 0))
			return (freestr(res));
		if (len == 0)
			return (res);
		buf[len] = '\0';
		len = get_strlen(buf);
		res = gnl_strjoin(res, buf, len);
		if (!res)
			return (0);
	}
	gnl_strlcpy(backup, buf + len, BUFFER_SIZE - len + 1);
	return (res);
}

char	*check_backup(char *backup, size_t len)
{
	char	*str;
	size_t	i;

	str = gnl_substr(backup, 0, len);
	if (!str)
		return (0);
	i = 0;
	while (backup[len + i])
		i++;
	gnl_strlcpy(backup, backup + len, i + 1);
	return (str);
}
