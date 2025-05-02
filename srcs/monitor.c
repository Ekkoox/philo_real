/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:49:38 by enschnei          #+#    #+#             */
/*   Updated: 2025/05/02 13:09:17 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_death(t_config *config)
{
    int status;

    status = 0;
    pthread_mutex_lock(&config->mutex_dead);
    if (config->status_death == 1)
        status = 1;
    pthread_mutex_unlock(&config->mutex_dead);
    return (status);
}

void set_up_death(t_config *config)
{
    pthread_mutex_lock(&config->mutex_dead);
    config->status_death = 1;
    pthread_mutex_unlock(&config->mutex_dead);
}

void monitor(void *arg)
{
    t_config *config;

    config = (t_config *)arg;
    wait_the_philo(config->start_time);
    while(check_deat(config) != EXIT_FAILURE)
    {
        if (stop_everything(config))
            break ;
        usleep (1000);
    }
    return (EXIT_SUCCESS);
}
