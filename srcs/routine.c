/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:42:26 by enschnei          #+#    #+#             */
/*   Updated: 2025/05/01 20:05:49 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_the_philo(int start_time)
{
	while (get_time() < start_time)
		continue ;
}

static void	routine_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->config->mutex_last_meal);
	philo->last_meal = philo->config->start_time;
	pthread_mutex_unlock(&philo->config->mutex_last_meal);
	wait_the_philo(philo->config->start_time);
	if (philo->config->nbr_philo == 1)
		return (NULL);
    if (philo->position % 2)
        ft_usleep(philo->config, philo->config->time_to_eat);
    while(check_death(philo->config) != EXIT_FAILURE)
    {
        print_eat(philo);
        print_sleep(philo);
        print_thinking(philo);
    }
	return (NULL);
}

int	start_routine(t_config *config)
{
	int	i;

	i = 0;
	config->start_time = get_time() + (config->nbr_philo * 10);
	while (i < config->nbr_philo)
	{
		config->philo[i].last_meal = config->start_time;
		if (pthread_create(&config->philo[i].thread, NULL, &routine_philo,
				&config->philo[i]))
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_create(&config->monitor, NULL, &monitor, &config->monitor))
	    return (EXIT_FAILURE);
	if (join_philo(config) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
