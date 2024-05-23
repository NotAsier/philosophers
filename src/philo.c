/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:39:36 by aarranz-          #+#    #+#             */
/*   Updated: 2024/05/23 15:11:22 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philos(t_params *params, t_philo *philo)
{
	int		i;
	t_philo	*tmp;
	
	i = 0;
	tmp = ft_lstnew(NULL);

	printf("[%d]\n", tmp->id);
	while (i < params->philo_count)
	{
		printf("%d", tmp->id);
		ft_lstadd_back(philo, tmp);
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
}

void	parse_args(t_params *params, char **argv)
{
	params->philo_count = philo_atoi(argv[1]);
	params->die = philo_atoi(argv[2]);
	params->eat = philo_atoi(argv[3]);
	params->sleep = philo_atoi(argv[4]);
	params->eat_count = philo_atoi(argv[5]);
	/*printf("%d\n",params->philo_count);
	printf("%d\n",params->die);
	printf("%d\n",params->eat);
	printf("%d\n",params->sleep);
	printf("%d\n",params->eat_count);*/
}

int	main(int argc, char **argv)
{
    t_params	*params;
	t_philo		*philo;

	params = (t_params *)malloc(sizeof(t_params));
	philo = (t_philo *)malloc(sizeof(t_philo));
	if(argc == 5 || argc == 6)
	{
		init_struct(params);
		parse_args(params, argv);
		create_philos(params, philo);
	}
}