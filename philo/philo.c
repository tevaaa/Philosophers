/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:53:23 by tandre            #+#    #+#             */
/*   Updated: 2022/11/28 20:57:09 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_philo_u	*p_u;
	
	p_u = args;
	p_u->start_time = get_time();
	p_u->last_eat = get_time();
	while (1)
	{
		philo_think(p_u);
		if (!philo_eat(p_u))
		{
			printf("%dms %d is dead\n",t_stamp(p_u), p_u->id + 1);
			exit(1);
		}
		philo_sleep(p_u);
	}
	return (0);
}

void	*watch(void **args)
{
	t_philo_u	**list;
	int			i;
	
	list = (t_philo_u **) args;
	i = 0;
	while (1)
	{
		while (i < list[0]->p->philo_n)
		{
			printf("%lld\n", list[i]->last_eat);
			i ++;
		}
	}
	return (0);
}

int	init_philo(t_philo_u *list, t_philo *p)
{
	int	i;
	i = 0;
	
	pthread_create(&p->watcher, 0, &watch (void *) list);
	pthread_mutex_init(p->talk, 0);
	while (i < p->philo_n)
	{
		if (i % 2 == 1)
			ft_usleep(5);
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