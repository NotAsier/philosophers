/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:39:36 by aarranz-          #+#    #+#             */
/*   Updated: 2024/06/14 12:20:01 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_params	*params;
	t_philo		*philo;

	params = (t_params *)malloc(sizeof(t_params));
	philo = NULL;
	if (argc == 5 || argc == 6)
	{
		init_struct(params);
		parse_args(params, argv);
		create_philos(params, &philo);
		if (params->philo_count != 1)
			philos_threads(params, &philo);
		else
			the_choosen_one(&philo);
	}
}
