/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:09:40 by aarranz-          #+#    #+#             */
/*   Updated: 2024/06/13 14:36:23 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*watch(void *arg)
{
	t_philo		*philo;

	philo = arg;
	ft_usleep(philo->params->die - 50);
	while (philo->next && philo->params->dead != 1)
	{
		if (ft_time() - philo->eat_start > philo->params->die)
		{
			philo->params->dead = 1;
			print_p(philo, 4);
		}
		philo = philo->next;
	}
	return (NULL);
}
