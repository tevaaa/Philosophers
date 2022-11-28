/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:53:23 by tandre            #+#    #+#             */
/*   Updated: 2022/11/28 18:06:02 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
*/

// pthread_t <-- structure
// pthread_create(&pthread_t t, 0, &routine, 0);

void	*routine(void *args)
{
	t_philo_u	*p_u;
	struct timeval start_time;
	
	p_u = (t_philo_u *) args;
	gettimeofday(&start_time, 0);
	p_u->start_time = (start_time.tv_sec * 1000) + (start_time.tv_usec / 1000);
	p_u->last_eat = t_stamp(p_u);
	while (1)
	{
		philo_think(p_u);
		if (!philo_eat(p_u))
		{
			printf("%d is dead\n", p_u->id + 1);
			exit(1);
		}
		philo_sleep(p_u);
	}
	return (0);
}

int	init_philo(t_philo_u *list, t_philo *p)
{
	int	i;
	i = 0;
	
	pthread_mutex_init(p->talk, 0);
	while (i < p->philo_n)
	{
		if (i % 2 == 1)
			ft_usleep(10);
		list[i].id = i;
		list[i].p = p;
		if (i == 0)
			list[i].left = p->philo_n - 1;
		else
			list[i].left = i - 1;
		list[i].right = i;
		if (pthread_create(&list->p->arr_th[i], 0, &routine, (void *) &list[i]))
		{
			printf("error : could not create thread %d\n", i);
			return (0);
		}
		i ++;
	}
	return (1);
}

void	join_philo(t_philo_u *l)
{
	int	i;

	i = 0;
	while (i < l->p->philo_n)
	{
		pthread_join(l->p->arr_th[i], 0);
		i ++;
	}
}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_philo_u	*list;

	philo = malloc(sizeof(t_philo) * 1);
	if (!parsing(argc, argv, philo))
		return (1);
	philo->arr_th = malloc(sizeof(pthread_t) * philo->philo_n);
	list = malloc(sizeof(t_philo_u) * philo->philo_n);
	init_forks(philo);
	if (!init_philo(list, philo))
		return (1);
	join_philo(list);
	return (0);
}