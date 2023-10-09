/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:19:29 by sgo               #+#    #+#             */
/*   Updated: 2023/10/09 18:29:01 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char *argv[])
{
	t_args	args;
	t_philo	*philos;

	if (argc < 5 || argc > 6)
	{
		return (1);
	}
	if (init_args(argc, argv, &args) == ERROR)
		return (ERROR);
	philos = init_philos(&args);
	if (!philos)
		return (ERROR);
	// printf("philos : %d, time_to_die : %d, time_to_eat : %d, time_to_sleep : %d, [must_eat] : %d\n ", args.philo_num, args.time_die, args.time_eat, args.time_sleep, args.must_eat);
	start_dining(philos, &args);
	// printf("식사 시작은 끝났어\n");
	monitoring(philos, &args);
	wait_finish(philos, &args);
	// printf("프로그램이 끝났어\n");
	return (SUCCESS);
}
