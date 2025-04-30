/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:25:59 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/30 15:00:18 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_config config;

    if (parsing(ac, av, &config) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    // if (init_routine(&config))
    //     return (EXIT_FAILURE);
    // if (init_mutex(&config))
    //     return (EXIT_FAILURE);
    // if (start_routine(&config))
    //     return (EXIT_FAILURE);
    // free_and_clean(&config);
    return (EXIT_SUCCESS);
}