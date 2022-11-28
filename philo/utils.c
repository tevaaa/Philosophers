/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:03:55 by tandre            #+#    #+#             */
/*   Updated: 2022/11/28 14:56:34y tandre           ###   ########.fr       */
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
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + (str[i] - '0');
		i ++;
	}
	return (res * sign);
}

long	get_time()
{
	struct timeval t;
	gettimeofday(&t, 0);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

int	t_stamp(t_philo_u *p)
{
	return (get_time() - p->start_time);
}

void	ft_usleep(int time)
{
	long	temp;

	temp = get_time();
	usleep(time * 0.95 * 1000);
	while (get_time() - temp <= time)
		usleep(1);
}