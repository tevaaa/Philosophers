/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:03:55 by tandre            #+#    #+#             */
/*   Updated: 2022/11/26 19:18:10 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

void	ft_putstr_fd(char const *s, int fd)
{
	char	*str;

	str = (char *) s;
	while (*str)
	{
		write(fd, str, 1);
		str ++;
	}
}

int	ft_isdigit(char c)
{
	return (c <= '9' && c >= '0');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == '\v'))
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i ++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i ++;
	}
	return (res * sign);
}

int	t_stamp(t_philo *p)
{
	struct timeval actual_time;
	
	gettimeofday(&actual_time, 0);
	return (actual_time.tv_usec - p->start_time);
}