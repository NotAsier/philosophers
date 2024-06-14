/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:48:32 by aarranz-          #+#    #+#             */
/*   Updated: 2024/06/14 12:29:23 by aarranz-         ###   ########.fr       */
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

void	the_choosen_one(t_philo **philo)
{
	t_philo	*current;

	current = *philo;
	current->params->start = ft_time();
	pthread_create(&current->thread, NULL, one_case, current);
	pthread_join(current->thread, NULL);
}

void	*one_case(void *arg)
{
	t_philo		*philo;

	philo = arg;
	print_p(philo, 0);
	ft_usleep(philo->params->die);
	print_p(philo, 4);
	return (NULL);
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
			if (i == philo->params->eat_max)
				philo->params->philos_eaten++;
		}
		if (philo->params->dead != 1)
			philo_sleep(philo);
		if (philo->params->dead != 1)
			print_p(philo, 3);
		if (i == philo->params->eat_max)
			break ;
	}
	return (NULL);
}
