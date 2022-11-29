/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:53:26 by tandre            #+#    #+#             */
/*   Updated: 2022/11/29 19:20:29 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define BAD_ARGS "Bad numbers of argument: need 4 or 5\n"

typedef struct s_philo
{
	pthread_t		*arr_th;
	pthread_mutex_t	*forks;
	pthread_mutex_t	talk;
	int				philo_n;
	int				die;
	int				eat;
	int				sleep;
	int				n_to_eat;
}	t_philo;

typedef struct s_philo_u
{
	int				id;
	t_philo			*p;
	pthread_t		*observer;
	long long int	start_time;
	long long int	time_in;
	long long int	last_eat;
	int				eat_n;
	int				left;
	int				right;
}	t_philo_u;

void	ft_putstr_fd(char const *s, int fd);
int		ft_atoi(const char *str);
int		parsing(int argc, char **argv, t_philo *philo);
void	init_forks(t_philo *philo);
int		t_stamp(t_philo_u *p);
void	ft_usleep(int time);
int		philo_eat(t_philo_u *p_u);
void	philo_sleep(t_philo_u *p_u);
void	philo_think(t_philo_u *p_u);
long	get_time(void);
#endif