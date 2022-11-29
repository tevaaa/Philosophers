/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:53:23 by tandre            #+#    #+#             */
/*   Updated: 2022/11/29 19:32:54 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_philo_u	*p_u;

	p_u = args;
	p_u->eat_n = 0;
	p_u->last_eat = get_time();
	p_u->time_in = p_u->last_eat - p_u->start_time;
	if (p_u->id % 2 == 1)
		ft_usleep(p_u->p->die / 2.5);
	while (1)
	{
		philo_think(p_u);
		if (!philo_eat(p_u))
		{
			free(p_u->observer);
			exit(1);
		}
		p_u->eat_n += 1;
		philo_sleep(p_u);
	}
	return (0);
}

int	all_eat(t_philo_u *list, int size)
{
	int	i;
	int	eat_n;

	i = 0;
	eat_n = list->p->n_to_eat;
	while (i < size)
	{
		if (list[i].eat_n != eat_n)
			return (0);
		i ++;
	}
	free(list->observer);
	exit(0);
	return (1);
}

void	*observe(void *args)
{
	t_philo_u	*list;
	int			size;
	int			i;

	list = args;
	size = list->p->philo_n;
	while (1)
	{
		i = 0;
		while (i < size)
		{
			if (get_time() - list[i].time_in - list[i].last_eat > list->p->die)
			{
				pthread_mutex_lock(&list->p->talk);
				printf("%lld %d is dead\n",
					t_stamp(list) - list[i].time_in, list[i].id + 1);
				pthread_mutex_destroy(&list->p->talk);
				free(list->observer);
				exit(0);
			}
			all_eat(list, size);
			i ++;
		}
	}
	return (0);
}

void	init_philo(t_philo_u *list, t_philo *p)
{
	int				i;
	long long int	start_time;

	list->observer = malloc(sizeof(pthread_t) * 1);
	i = -1;
	start_time = get_time();
	pthread_mutex_init(&p->talk, 0);
	while (++i < p->philo_n)
	{
		list[i].start_time = start_time;
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
			exit(1);
		}
	}
	ft_usleep(10);
	pthread_create(list->observer, 0, &observe, (void *) list);
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
	init_philo(list, philo);
	while (1)
		;
	return (0);
}
