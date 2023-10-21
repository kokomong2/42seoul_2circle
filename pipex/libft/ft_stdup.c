/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:58:51 by sgo               #+#    #+#             */
/*   Updated: 2023/09/13 21:05:03 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*str;
	char	*start;

	len = 0;
	while (s1[len])
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	start = str;
	while (*s1)
		*str++ = *s1++;
	*str = '\0';
	return (start);
}
