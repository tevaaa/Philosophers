/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:07:40 by tandre            #+#    #+#             */
/*   Updated: 2022/11/28 14:22:40 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_times(int argc, char **argv, t_philo *p)
{
	if (argc == 6)
		p->n_to_eat = ft_atoi(argv[5]);
	p->philo_n = ft_atoi(argv[1]);
	p->die = ft_atoi(argv[2]);
	p->eat = ft_atoi(argv[3]);
	p->sleep = ft_atoi(argv[4]);
	if (p->philo_n <= 0)
		return (0);
	return (1);
}

int	parsing(int argc, char **argv, t_philo *philo)
{
	if (argc != 6 && argc != 5)
	{
		ft_putstr_fd(BAD_ARGS, 2);
		return(0);
	}
	if (!parse_times(argc, argv, philo))
		return (0);
	return(1);
}