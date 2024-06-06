/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:30:53 by aarranz-          #+#    #+#             */
/*   Updated: 2024/06/06 12:53:32 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_p(t_philo *philo, int id)
{
	if(id == 0)
	printf("%ld  %d has taken a fork\n", philo->params->time, philo->id );
	if(id == 1)
	printf("%ld  %d is eating\n", philo->params->time, philo->id);
	if(id == 2)
	printf("%ld  %d is sleeping\n", philo->params->time, philo->id);
	if(id == 3)
	printf("%ld  %d is thinking\n", philo->params->time, philo->id);
	if(id == 4)
	printf("%ld  %d died\n", philo->params->time, philo->id);
}
