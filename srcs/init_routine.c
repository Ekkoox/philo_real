/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:09:16 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/30 15:17:13 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_philo(t_config *config)
{
    int i;

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

int init(t_config *config)
{
    init_philo(config);
    return (EXIT_SUCCESS);
}