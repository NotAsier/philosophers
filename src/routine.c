/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:48:32 by aarranz-          #+#    #+#             */
/*   Updated: 2024/06/03 12:52:24 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = arg;
	if(philo->id % 2 == 0)
		usleep(1000);
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->next->fork);
	printf("soy el pshilosofo [%d] y he tomado el tenedor del philososfo [%d]\n",
	philo->id, philo->next->id);
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
	return (NULL);
}