/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:48:30 by aarranz-          #+#    #+#             */
/*   Updated: 2024/06/14 11:49:12 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philos(t_philo **head)
{
	t_philo	*current;
	t_philo	*next;
	int		i;
	int		philo_count;

	current = *head;
	i = 0;
	philo_count = current->params->philo_count;
	while (i < philo_count)
	{
		next = current->next;
		pthread_mutex_destroy(&current->fork);
		free(current);
		current = next;
		i++;
	}
}

void	free_params(t_params *params)
{
	pthread_mutex_destroy(&params->print);
	free(params);
}
