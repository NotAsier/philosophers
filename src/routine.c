/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:48:32 by aarranz-          #+#    #+#             */
/*   Updated: 2024/06/13 14:48:22 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	print_p(philo, 2);
	ft_usleep(philo->params->sleep);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	print_p(philo, 0);
	pthread_mutex_lock(&philo->next->fork);
	print_p(philo, 0);
	print_p(philo, 1);
	philo->eat_start = ft_time();
	ft_usleep(philo->params->eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	*routine(void *arg)
{
	t_philo		*philo;
	int			i;

	i = 0;
	philo = arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->params->eat);
	while (1 && philo->params->dead != 1)
	{
		if (philo->params->dead != 1)
		{
			philo_eat(philo);
			i++;
		}
		if (philo->params->dead != 1)
			philo_sleep(philo);
		if (philo->params->dead != 1)
			print_p(philo, 3);
		if (i == philo->params->eat_count)
			break ;
	}
	return (NULL);
}
