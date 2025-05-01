/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:49:38 by enschnei          #+#    #+#             */
/*   Updated: 2025/05/01 20:08:22 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
