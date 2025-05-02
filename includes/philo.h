/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:26:22 by enschnei          #+#    #+#             */
/*   Updated: 2025/05/02 13:06:41 by enschnei         ###   ########.fr       */
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

typedef struct s_config
{
	int					nbr_philo;
	int					max_meals;
	int					start_time;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					status_death;
	pthread_t			monitor;
	pthread_mutex_t		*forks;
	pthread_mutex_t		mutex_dead;
	pthread_mutex_t		mutex_print;
	pthread_mutex_t		mutex_last_meal;
	pthread_mutex_t		mutex_count_meal;
	t_philo				*philo;
}						t_config;

typedef struct s_philo
{
	int					id;
	int					position;
	int					nbr_meal;
	int					last_meal;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_config			*config;
}						t_philo;

// INIT
int						init(t_config *config);
int						init_mutex(t_config *config);

// MONITOR
int 					check_death(t_config *config);
void 					monitor(void *arg);
void 					set_up_death(t_config *config);

// PARSING
int						parsing(int ac, char **av, t_config *config);
void					ft_putstr_fd(char *s, int fd);

// PRINT
int						print_eat(t_philo *philo);
int						print_sleep(t_philo *philo);
int						print_think(t_philo *philo);

// ROUTINE
int						start_routine(t_config *config);

// TIME
int						get_time(void);
void					wait_the_philo(int start_time);
void					ft_usleep(t_config *config, int time);

// UTILS
int						convert_nbr(char *str);
int						join_philo(t_config *config);

#endif