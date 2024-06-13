/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:30:53 by aarranz-          #+#    #+#             */
/*   Updated: 2024/06/13 14:34:03 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_p(t_philo *philo, int id)
{
	long	timestamp;

	timestamp = ft_time() - philo->params->start;
	pthread_mutex_lock(&philo->params->print);
	if (id == 0 && philo->params->dead != 1)
		printf ("%ld  %d has taken a fork\n", timestamp, philo->id);
	else if (id == 1 && philo->params->dead != 1)
		printf ("%ld  %d is eating\n", timestamp, philo->id);
	else if (id == 2 && philo->params->dead != 1)
		printf ("%ld  %d is sleeping\n", timestamp, philo->id);
	else if (id == 3 && philo->params->dead != 1)
		printf ("%ld  %d is thinking\n", timestamp, philo->id);
	else if (id == 4)
		printf ("%ld  %d died\n", timestamp, philo->id);
	pthread_mutex_unlock(&philo->params->print);
}
