/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:19:46 by sgo               #+#    #+#             */
/*   Updated: 2023/10/14 13:59:25 by sgo              ###   ########.fr       */
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

# define MSG_FORK		"has taken a fork"
# define MSG_EATING		"is eating"
# define MSG_SLEEPING	"is sleeping"
# define MSG_THINKING	"is thinking"
# define MSG_DIED		"died"

# define ARGC_ERROR		"Wrong argument! Please check usage."

# define SUCCESS 0
# define ERROR 1
# define FALSE -1

typedef struct s_args
{
	int					philo_num;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					must_eat;
	struct timeval		start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		finish_mutex;
	int					fin_cnt;
	pthread_mutex_t		print_mutex;
	int					finish;
}				t_args;

typedef struct s_philo
{
	int				philo_id;
	pthread_t		thread;
	t_args			*args;
	int				l_fork;
	int				r_fork;
	int				eat_cnt;
	pthread_mutex_t	last_eat_mutex;
	long long		last_eat;
}			t_philo;

int			ft_atoi(const char *str);
int			init_args(int argc, char *argv[], t_args *args);
t_philo		*init_philos(t_args *args);
int			init_fork(t_args *args);
void		*dining(t_philo *philo);
int			start_dining(t_philo *philos, t_args *args);
void		wait_finish(t_philo *philos, t_args *args);
int			mutex_printf(t_philo *philo, char *msg);
long long	get_time(t_philo *philo);
void		monitoring(t_philo *philo, t_args *args);
int			ft_usleep(long long time, t_philo *philo);
int			print_error(char *msg);
void		free_args(t_args *args);
void		free_philos(t_philo *philo, t_args *args);
void		finish_eating(t_args *args);

#endif