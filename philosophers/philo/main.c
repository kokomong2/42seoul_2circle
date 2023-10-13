/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:19:29 by sgo               #+#    #+#             */
/*   Updated: 2023/10/13 00:35:35 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	foo(void)
{
	system("leaks philo");
}

int main(int argc, char *argv[])
{
	t_args	args;
	t_philo	*philos;

	// atexit(foo);	
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
	start_dining(philos, &args); // dining에서 실패시 어떻게 처리할지
	monitoring(philos, &args);
	wait_finish(philos, &args);
	free_philos(philos, &args);
	free_args(&args);
	return (SUCCESS);
}
