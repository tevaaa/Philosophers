/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:41:21 by tandre            #+#    #+#             */
/*   Updated: 2022/11/29 19:15:29 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo_u *p_u)
{
	long int	time;

	pthread_mutex_lock(&p_u->p->forks[p_u->left]);
	time = t_stamp(p_u);
	pthread_mutex_lock(&p_u->p->talk);
	printf("%ld %d has taken a fork\n", time, p_u->id + 1);
	pthread_mutex_unlock(&p_u->p->talk);
	pthread_mutex_lock(&p_u->p->forks[p_u->right]);
	time = t_stamp(p_u);
	pthread_mutex_lock(&p_u->p->talk);
	if (get_time() - p_u->time_in - p_u->last_eat > p_u->p->die)
		return (0);
	p_u->last_eat = get_time();
	printf("%ld %d has taken a fork\n", time, p_u->id + 1);
	printf("%ld %d is eating\n", time, p_u->id + 1);
	pthread_mutex_unlock(&p_u->p->talk);
	ft_usleep(p_u->p->eat - 1);
	pthread_mutex_unlock(&p_u->p->forks[p_u->left]);
	pthread_mutex_unlock(&p_u->p->forks[p_u->right]);
	return (1);
}

void	philo_sleep(t_philo_u *p_u)
{
	long int	time;

	time = t_stamp(p_u);
	pthread_mutex_lock(&p_u->p->talk);
	printf("%ld %d is sleeping\n", time, p_u->id + 1);
	pthread_mutex_unlock(&p_u->p->talk);
	ft_usleep(p_u->p->sleep - 1);
}

void	philo_think(t_philo_u *p_u)
{
	long int	time;

	time = t_stamp(p_u);
	pthread_mutex_lock(&p_u->p->talk);
	printf("%ld %d is thinking\n", time, p_u->id + 1);
	pthread_mutex_unlock(&p_u->p->talk);
}
