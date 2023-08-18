/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:09:53 by sgo               #+#    #+#             */
/*   Updated: 2023/08/18 17:16:43 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:25:56 by sgo               #+#    #+#             */
/*   Updated: 2023/03/18 16:25:59 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	getnumsize(int n);

char	*ft_itoa(int n)
{
	size_t		len;
	char		*res;
	long long	ln;

	ln = n;
	len = getnumsize(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	if (ln == 0)
		res[0] = '0';
	res[len] = '\0';
	if (ln < 0)
	{
		res[0] = '-';
		ln = -ln;
	}
	while (--len > 0)
	{
		res[len] = ln % 10 + '0';
		ln = ln / 10;
	}
	if (ln > 0)
		res[0] = ln % 10 + '0';
	return (res);
}

static int	getnumsize(int n)
{
	size_t		len;
	long long	ln;

	len = 0;
	ln = n;
	if (ln <= 0)
	{
		len++;
		ln = -ln;
	}
	while (ln > 0)
	{
		len++;
		ln = ln / 10;
	}
	return (len);
}

void	write_num(int num)
{
	char	*str;
	
	str = ft_itoa(num);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
}
