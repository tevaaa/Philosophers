/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:53:26 by tandre            #+#    #+#             */
/*   Updated: 2022/11/26 19:18:18 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

#define BAD_ARGS "Bad numbers of argument: need 4 or 5\n"

typedef struct s_philo
{
	pthread_t		*arr_th;
	pthread_mutex_t	*forks;
	int				philo_n;
	int				die;
	int				eat;
	int				sleep;
	int				n_to_eat;
	int				start_time;
}	t_philo;

typedef struct s_philo_u
{
	int		id;
	t_philo	*p;
	int		dead;
	int		left;
	int		right;
}	t_philo_u;

void	ft_putstr_fd(char const *s, int fd);
int		ft_atoi(const char *str);
int		parsing(int argc, char **argv, t_philo *philo);
void	init_forks(t_philo *philo);
int		t_stamp(t_philo *p);
#endif