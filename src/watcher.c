/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:46:48 by aarranz-          #+#    #+#             */
/*   Updated: 2024/06/12 11:15:37 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *watch(void *arg)
{
	t_philo		*philo;

    philo = arg;
    ft_usleep(philo->params->die - 10);
    while (philo->next && philo->params->dead != 1)
    {
        if(ft_time() - philo->eat_start > philo->params->die)
        {
            printf("%ld %d\n", ft_time() - philo->eat_start, philo->params->die);
            philo->params->dead = 1;
        }
        philo = philo->next;
    }
    return (NULL);
}
