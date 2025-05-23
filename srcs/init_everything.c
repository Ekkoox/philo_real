/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:09:16 by enschnei          #+#    #+#             */
/*   Updated: 2025/05/05 15:27:00 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philo(t_config *config)
{
	int	i;

	i = 0;
	config->philo = malloc(sizeof(t_philo) * config->nbr_philo);
	if (!config->philo)
		return (EXIT_FAILURE);
	memset(config->philo, 0, sizeof(t_philo) * config->nbr_philo);
	while (i < config->nbr_philo)
	{
		config->philo[i].id = i + 1;
		config->philo[i].nbr_meal = 0;
		config->philo[i].config = config;
		config->philo[i].position = i + 1;
		i++;
	}
	return (EXIT_SUCCESS);
}

static void	init_fork_philo(t_philo *philo, int i)
{
	if (philo->position % 2 == 0)
	{
		philo->left_fork = &philo->config->forks[i];
		philo->right_fork = &philo->config->forks[(i + 1)
			% philo->config->nbr_philo];
	}
	else
	{
		philo->right_fork = &philo->config->forks[i];
		philo->left_fork = &philo->config->forks[(i + 1)
			% philo->config->nbr_philo];
	}
}

static int	init_forks(t_config *config)
{
	int	i;

	i = 0;
	config->forks = malloc(sizeof(pthread_mutex_t) * config->nbr_philo);
	if (!config->forks)
	{
		free(config->philo);
		return (EXIT_FAILURE);
	}
	while (i < config->nbr_philo)
	{
		if (pthread_mutex_init(&config->forks[i], NULL))
		{
			free(config->philo);
			free(config->forks);
			return (EXIT_FAILURE);
		}
		init_fork_philo(&config->philo[i], i);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init(t_config *config)
{
	if (init_philo(config) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_forks(config) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_mutex(t_config *config)
{
	if (pthread_mutex_init(&config->mutex_count_meal, NULL))
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&config->mutex_dead, NULL))
		return (pthread_mutex_destroy(&config->mutex_count_meal), EXIT_FAILURE);
	if (pthread_mutex_init(&config->mutex_last_meal, NULL))
		return (pthread_mutex_destroy(&config->mutex_count_meal),
			pthread_mutex_destroy(&config->mutex_dead), EXIT_FAILURE);
	if (pthread_mutex_init(&config->mutex_print, NULL))
		return (pthread_mutex_destroy(&config->mutex_count_meal),
			pthread_mutex_destroy(&config->mutex_dead),
			pthread_mutex_destroy(&config->mutex_last_meal), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
