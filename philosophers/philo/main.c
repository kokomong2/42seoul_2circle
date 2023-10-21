/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:19:29 by sgo               #+#    #+#             */
/*   Updated: 2023/10/14 13:19:10 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_args	args;
	t_philo	*philos;

	if (argc < 5 || argc > 6)
		return (print_error(ARGC_ERROR));
	if (init_args(argc, argv, &args) == ERROR)
		return (print_error(ARGC_ERROR));
	philos = init_philos(&args);
	if (!philos)
	{
		free_args(&args);
		return (ERROR);
	}
	start_dining(philos, &args);
	monitoring(philos, &args);
	wait_finish(philos, &args);
	free_philos(philos, &args);
	free_args(&args);
	return (SUCCESS);
}
