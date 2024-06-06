/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:22:33 by aarranz-          #+#    #+#             */
/*   Updated: 2024/06/06 12:56:47 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	create_philos(t_params *params, t_philo **philo)
{
	int		i;
	t_philo	*tmp;
	
	i = 0;
	
	tmp = ft_lstnew(NULL);
	*philo = tmp;
	while (i < params->philo_count)
	{
		tmp->id = i + 1;
		pthread_mutex_init(&tmp->fork, NULL);
		tmp->params = params;
		if (i + 1 == params->philo_count)
			tmp->next = *philo;
		else
			tmp->next = ft_lstnew(NULL);
		tmp = tmp->next;
		i++;
	}
}

void	init_struct(t_params *params)
{
	params->philo_count = 0;
	params->die = 0;
	params->eat = 0;
	params->sleep = 0;
	params->eat_count = 0;
    params->time = ft_time();
}

void	parse_args(t_params *params, char **argv)
{
	params->philo_count = philo_atoi(argv[1]);
	params->die = philo_atoi(argv[2]);
	params->eat = philo_atoi(argv[3]);
	params->sleep = philo_atoi(argv[4]);
	params->eat_count = philo_atoi(argv[5]);
}

void    philos_threads(t_params *params, t_philo  **philo)
{
    int i;
    t_philo *current;
    current = *philo;

    i = 0;
	while(i < params->philo_count)
	{
		pthread_create(&current->thread, NULL, routine, current);
		current = current->next;
		i++;
	}
	i = 0;
	while(i < params->philo_count)
	{
		pthread_join(current->thread, NULL);
		current = current->next;
		i++;
	}
}
