/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:53:23 by tandre            #+#    #+#             */
/*   Updated: 2022/11/26 19:21:23 by tandre           ###   ########.fr       */
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


	p_u = (t_philo_u *) args;
	while (!p_u->dead)
	{
		pthread_mutex_lock(&p_u->p->forks[p_u->left]);
		printf("%dms %d has taken a fork\n",t_stamp(p_u->p) , p_u->id + 1);
		pthread_mutex_lock(&p_u->p->forks[p_u->right]);
		printf("%dms %d has taken a fork\n",t_stamp(p_u->p) , p_u->id + 1);
		printf("%dms %d is eating\n",t_stamp(p_u->p) , p_u->id + 1);
		usleep(p_u->p->eat);
		pthread_mutex_unlock(&p_u->p->forks[p_u->left]);
		pthread_mutex_unlock(&p_u->p->forks[p_u->right]);
	}
	return (0);
}

int	init_philo(t_philo_u *list, t_philo *p)
{
	int	i;
	i = 0;
	
	while (i < p->philo_n)
	{
		list[i].id = i;
		list[i].p = p;
		list[i].dead = 0;
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

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_philo_u	*list;
	struct timeval start_time;

	philo = malloc(sizeof(t_philo) * 1);
	if (!parsing(argc, argv, philo))
		return (1);
	gettimeofday(&start_time, 0);
	philo->start_time = start_time.tv_usec;
	philo->arr_th = malloc(sizeof(pthread_t) * philo->philo_n);
	list = malloc(sizeof(t_philo_u) * philo->philo_n);
	init_forks(philo);
	if (!init_philo(list, philo))
		return (1);
	return (0);
}