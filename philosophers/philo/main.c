/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:19:29 by sgo               #+#    #+#             */
/*   Updated: 2023/10/11 19:14:11 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char *argv[])
{
	t_args	args;
	t_philo	*philos;

	if (argc < 5 || argc > 6)
		return (print_error(ARGC_ERROR));
	if (init_args(argc, argv, &args) == ERROR)
		return (print_error(ARGC_ERROR));
	printf("argvs : %d %d %d %d %d\n", args.philo_num, args.time_die, args.time_eat, args.time_sleep, args.must_eat);
	philos = init_philos(&args);
	if (!philos)
		return (ERROR);
	start_dining(philos, &args);
	monitoring(philos, &args);
	wait_finish(philos, &args);
	return (SUCCESS);
}
