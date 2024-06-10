/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:30:53 by aarranz-          #+#    #+#             */
/*   Updated: 2024/06/10 13:44:40 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_p(t_philo *philo, int id)
{
	if(id == 0)
		printf("%ld  %d has taken a fork\n",ft_time() - philo->params->start, philo->id );
	if(id == 1)
		printf("%ld  %d is eating\n", ((ft_time())-(philo->params->start)), philo->id);
	if(id == 2)
		printf("%ld  %d is sleeping\n", ((ft_time())-(philo->params->start)), philo->id);
	if(id == 3)
		printf("%ld  %d is thinking\n", ((ft_time())-(philo->params->start)), philo->id);
	if(id == 4)
		printf("%ld  %d died\n", ((ft_time())-(philo->params->start)), philo->id);
}
