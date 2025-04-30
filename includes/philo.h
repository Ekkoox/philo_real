/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:26:22 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/30 14:58:54 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo	t_philo;
typedef struct s_config	t_config;

typedef struct s_philo
{
	int					id;
	t_config			*config;
}						t_philo;

typedef struct s_config
{
	int					nbr_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					max_meals;
	t_philo				*philo;
}						t_config;

// PARSING
int						parsing(int ac, char **av, t_config *config);
void					ft_putstr_fd(char *s, int fd);

// UTILS
int						convert_nbr(char *str);

#endif