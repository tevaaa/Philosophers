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

int	t_stamp(t_philo_u *p)
{
	struct timeval t;
	long long int time;
	(void) p;
	gettimeofday(&t, 0);
	time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	return (time - p->start_time);
}

void	ft_usleep(int time)
{
	/*
	int	i;
	long int	temp;

	time *= 1000;
	temp = (time * 0.95);
	i = temp;
	while (i++ < time)
		usleep(1);
		*/
	usleep(time * 1000);
}