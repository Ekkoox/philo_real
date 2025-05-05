/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:49:38 by enschnei          #+#    #+#             */
/*   Updated: 2025/05/05 14:29:56 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	status_death(t_config *config)
{
	int	status;

	status = 0;
	pthread_mutex_lock(&config->mutex_dead);
	if (config->status_death == 1)
		status = 1;
	pthread_mutex_unlock(&config->mutex_dead);
	return (status);
}

void	set_up_death(t_config *config)
{
	pthread_mutex_lock(&config->mutex_dead);
	config->status_death = 1;
	pthread_mutex_unlock(&config->mutex_dead);
}

int	check_philo_death(t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->config->mutex_last_meal);
	time = get_time() - philo->last_meal;
	pthread_mutex_unlock(&philo->config->mutex_last_meal);
	if (time >= philo->config->time_to_die)
	{
		set_up_death(philo->config);
		usleep(1000);
		print_msg(philo, 5);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	stop_everything(t_config *config)
{
	int	i;
	int	all_eat;

	i = 0;
	all_eat = config->nbr_philo;
	while (i < config->nbr_philo)
	{
		if (check_philo_death(&config->philo[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (config->max_meals)
		{
			pthread_mutex_lock(&config->mutex_count_meal);
			if (config->philo[i].nbr_meal < config->max_meals)
				all_eat = 0;
			pthread_mutex_unlock(&config->mutex_count_meal);
		}
		i++;
	}
	if (config->max_meals && all_eat)
	{
		set_up_death(config);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	*monitor(void *arg)
{
	t_config	*config;

	config = (t_config *)arg;
	wait_the_philo(config->start_time);
	while (status_death(config) != EXIT_FAILURE)
	{
		if (stop_everything(config) == EXIT_FAILURE)
			break ;
		usleep(1000);
	}
	return (NULL);
}
