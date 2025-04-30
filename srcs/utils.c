/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:39:35 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/30 15:00:39 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_whitiespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\v'
		|| c == '\f')
		return (0);
	return (1);
}

static int	is_digit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (EXIT_FAILURE);
	while (is_whitiespace(str[i]) == 0)
		i++;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (ft_putstr_fd("Error: only number accepted in parameters\n",
					2), 1);
		i++;
	}
	return (0);
}

int	convert_nbr(char *str)
{
	long int	nbr;
	int			i;

	i = 0;
	nbr = 0;
	if (is_digit(str) == 1)
		return (EXIT_FAILURE);
	while (str[i])
	{
		nbr = (nbr * 10) + (str[i] - 48);
		if (nbr > INT_MAX)
			return (ft_putstr_fd("Error: number out of range\n", 2), -1);
		i++;
	}
	return ((int)nbr);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
