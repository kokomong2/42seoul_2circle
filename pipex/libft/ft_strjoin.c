/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:37:29 by sgo               #+#    #+#             */
/*   Updated: 2023/09/13 21:05:03 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*ret;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!ret)
		return (0);
	ft_memcpy(ret, s1, len_s1);
	ft_memcpy(ret + len_s1, s2, len_s2);
	ret[len_s1 + len_s2] = 0;
	return (ret);
}
