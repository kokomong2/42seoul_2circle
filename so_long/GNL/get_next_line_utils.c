/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:28:17 by sgo               #+#    #+#             */
/*   Updated: 2023/08/09 17:04:37 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2, size_t len_s2)
{
	size_t		len_s1;
	char		*ret;
	size_t		i;
	size_t		tlen;

	len_s1 = get_strlen(s1);
	ret = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!ret)
		return (freestr(s1));
	tlen = 0;
	i = 0;
	while (i < len_s1)
		ret[tlen++] = s1[i++];
	i = 0;
	while (i < len_s2 && s2[i] != '\n')
		ret[tlen++] = s2[i++];
	ret[tlen] = 0;
	freestr(s1);
	return (ret);
}

int	get_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (*(str + len) && *(str + len) != '\n')
		len++;
	if (*(str + len) == '\n')
		len++;
	return (len);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*tmp;
	size_t	i;
	size_t	slen;

	slen = 0;
	while (s[slen])
		slen++;
	if (!slen || slen - 1 < start)
		len = 0;
	else if (slen - start < len)
		len = slen - start;
	i = 0;
	tmp = (char *)malloc(len + 1);
	if (!tmp)
		return (0);
	while (i < len && s[start + i])
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*freestr(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	return (0);
}

void	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*(src + i) && (i + 1 < size))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	if (size > 0)
		*(dest + i) = '\0';
}
