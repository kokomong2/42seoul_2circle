/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:19:46 by sgo               #+#    #+#             */
/*   Updated: 2023/10/09 18:10:05 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define MSG_FORK "has taken a fork"
# define MSG_EATING "is eating"
# define MSG_SLEEPING "is sleeping"
# define MSG_THINKING "is thinking"
# define MSG_DIED "died"

# define SUCCESS 0
# define ERROR 1
# define FALSE 2

typedef struct s_args
{
	int					philo_num;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					must_eat;
	struct timeval		first_time;
	int					finish;
	int					fin_cnt;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_mutex;
}				t_args;

typedef struct s_philo
{
	int			philo_id;
	pthread_t	thread;
	t_args		*args;
	int			l_fork;
	int			r_fork;
	int			eat_cnt;
	int			status_eating;
	int			status_sleeping;
	int			stauts_thinking;
	int			status_died;
	int			last_eat;
}				t_philo;

int		ft_atoi(const char *str);
int 	init_args(int argc, char *argv[], t_args *args);
t_philo *init_philos(t_args *args);
int 	init_fork(t_args *args);
void    *dining(t_philo *philo);
int		start_dining(t_philo *philos, t_args *args);
int 	wait_finish(t_philo *philos, t_args *args);
int		mutex_printf(t_philo *philo, int time, char *msg);
int 	get_time(t_args *args);
void	monitoring(t_philo *philo, t_args *args);

# endif