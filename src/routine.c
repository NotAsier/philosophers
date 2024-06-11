/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:48:32 by aarranz-          #+#    #+#             */
/*   Updated: 2024/06/11 12:53:14 by aarranz-         ###   ########.fr       */
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
	print_p(philo, 1);
	philo->eat_start = ft_time() - philo->params->start;
	ft_usleep(philo->params->eat);
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
}

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = arg;
	if(philo->id % 2 == 0)
		ft_usleep(100);
	while(1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		print_p(philo, 3);
	}
	
	return (NULL);
}
