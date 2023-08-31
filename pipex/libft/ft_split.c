/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:41:40 by sgo               #+#    #+#             */
/*   Updated: 2023/08/29 20:07:52 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	getwords(char const *s, char c);
static char		**getres(char **result, size_t wordcnt, char const *s, char c);
static char		**freeresult(size_t i, char **result);

char	**ft_split(char const *s, char c)
{
	size_t	wordcnt;
	char	**res;

	if (!s)
		return (0);
	wordcnt = getwords(s, c);
	res = (char **)malloc(sizeof(char *) * (wordcnt + 1));
	if (!res)
		return (0);
	res = getres(res, wordcnt, s, c);
	if (!res)
		return (0);
	return (res);
}

static size_t	getwords(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			cnt++;
		while (s[i] != c && s[i])
			i++;
	}
	return (cnt);
}

static char	**getres(char **result, size_t wordcnt, char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (i < wordcnt)
	{
		while (*s == c)
			s++;
		len = 0;
		while (*(s + len) != c && *(s + len))
			len++;
		result[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!result[i])
			return (freeresult(i, result));
		ft_strlcpy(result[i], s, len + 1);
		s += len;
		i++;
	}
	result[i] = 0;
	return (result);
}

static char	**freeresult(size_t i, char **result)
{
	size_t	index;

	index = 0;
	while (index < i)
	{
		free(result[index]);
		index++;
	}
	free(result);
	return (0);
}
