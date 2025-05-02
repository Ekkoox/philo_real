/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:27:32 by enschnei          #+#    #+#             */
/*   Updated: 2025/05/02 13:10:36 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *philo, int message_value)
{
	pthread_mutex_lock(&philo->config->mutex_print);
	if (check_death(philo->config) == EXIT_FAILURE && message_value != 5)
    {
        pthread_mutex_unlock(&philo->config->mutex_print);
        return ;
    }
	if (message_value == 1)
		printf("%u %d has taken a fork\n", get_time - philo->config->start_time,
			philo->id);
	else if (message_value == 2)
		printf("%u %d is eating\n", get_time - philo->config->start_time,
			philo->id);
	else if (message_value == 3)
		printf("%u %d is sleeping\n", get_time - philo->config->start_time,
			philo->id);
	else if (message_value == 4)
		printf("%u %d is thinking\n", get_time - philo->config->start_time,
			philo->id);
	else if (message_value == 5)
	{
		printf("%u %d died\n", get_time - philo->config->start_time, philo->id);
		set_up_death(philo->config);
	}
	pthread_mutex_unlock(&philo->config->mutex_print);
}

int	print_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_msg(philo, 1);
	pthread_mutex_lock(philo->right_fork);
	print_msg(philo, 1);
	if (check_death(philo->config) == EXIT_FAILURE)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthead_mutex_unlock(philo->left_fork);
		return (EXIT_FAILURE);
	}
	print_msg(philo, 2);
	phtread_mutex_lock(&philo->config->mutex_last_meal);
	philo->last_meal = get_time();
	phtread_mutex_unlock(&philo->config->mutex_last_meal);
	ft_usleep(philo->config, philo->config->time_to_eat);
	if (check_death(philo->config) != EXIT_FAILURE)
	{
		pthread_mutex_lock(&philo->config->mutex_count_meal);
		philo->nbr_meal++;
		pthread_mutex_unlock(&philo->config->mutex_count_meal);
	}
	pthread_mutex_unlock(philo->right_fork);
	pthead_mutex_unlock(philo->left_fork);
	return (EXIT_SUCCESS);
}

int	print_sleep(t_philo *philo)
{
	if (check_death(philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	print_msg(philo, 3);
	ft_usleep(philo->config, philo->config->time_to_sleep);
	return (EXIT_SUCCESS);
}

int	print_think(t_philo *philo)
{
	if (check_death(philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	print_msg(philo, 4);
    if (philo->config->nbr_philo % 2 == 0)
        return (EXIT_SUCCESS);
    ft_usleep (philo->config, 100);
	return (EXIT_SUCCESS);
}
