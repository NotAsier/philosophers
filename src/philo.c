/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:39:36 by aarranz-          #+#    #+#             */
/*   Updated: 2024/06/13 14:22:14 by aarranz-         ###   ########.fr       */
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
		philos_threads(params, &philo);
	}
}
