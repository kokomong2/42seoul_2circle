/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:45:59 by sgo               #+#    #+#             */
/*   Updated: 2023/08/29 20:07:52 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*tmp;
	size_t			i;
	unsigned int	slen;

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
