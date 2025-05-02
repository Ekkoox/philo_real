/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:38:08 by enschnei          #+#    #+#             */
/*   Updated: 2025/05/02 16:19:41 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(int ac, char **av, t_config *config)
{
	config->nbr_philo = convert_nbr(av[1]);
	config->time_to_die = convert_nbr(av[2]);
	config->time_to_eat = convert_nbr(av[3]);
	config->time_to_sleep = convert_nbr(av[4]);
	if (ac == 6)
		config->max_meals = convert_nbr(av[5]);
	else
		config->max_meals = 0;
	if (config->nbr_philo < 1 || config->time_to_die < 60
		|| config->time_to_eat < 60 || config->time_to_sleep < 60 || (ac == 6
			&& config->max_meals < 1))
		return (ft_putstr_fd("Error: wrong arguments\n", 2), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
