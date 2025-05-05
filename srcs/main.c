/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:25:59 by enschnei          #+#    #+#             */
/*   Updated: 2025/05/05 15:36:38 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	free_and_clean(t_config *config)
{
	int	i;

	i = 0;
	while (i < config->nbr_philo)
	{
		pthread_mutex_destroy(&config->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&config->mutex_count_meal);
	pthread_mutex_destroy(&config->mutex_dead);
	pthread_mutex_destroy(&config->mutex_last_meal);
	pthread_mutex_destroy(&config->mutex_print);
	free(config->forks);
	free(config->philo);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_config	config;

	if (parsing(ac, av, &config) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init(&config) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_mutex(&config) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (start_routine(&config) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	free_and_clean(&config);
	return (EXIT_SUCCESS);
}
