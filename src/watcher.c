/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:46:48 by aarranz-          #+#    #+#             */
/*   Updated: 2024/06/11 12:58:31 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void watch(t_philo *philo)
{
    while (philo->next)
    {
        if(ft_time() - philo->eat_start > philo->para->eat)
            //insertar boolean para para parar la simulacion
        philo = philo->next;
    }
}