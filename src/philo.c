/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:39:36 by aarranz-          #+#    #+#             */
/*   Updated: 2024/06/03 12:47:30 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	int 		i;

	params = (t_params *)malloc(sizeof(t_params));
	philo = NULL;
	if(argc == 5 || argc == 6)
	{
		init_struct(params);
		parse_args(params, argv);
		create_philos(params, &philo);
	}
	i = 0;
	while(i < params->philo_count)
	{
		pthread_create(&philo->thread, NULL, routine, philo);
		philo = philo->next;
		i++;
	}
	i = 0;
	while(i < params->philo_count)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
		i++;
	}
}

	/*pthread_t	philo->thread; // Variable hilo
	pthread_create(&philo->thread, NULL, routine, current); // Crea el hilo y ejecuta la función routine con argumento current	
	pthread_join(philo->thread, NULL); // Espera a que el hilo en si termine
	
	mutex_t		fork; // Variable mutex
	pthread_mutex_init(&fork); // Inicializa el mutex (desbloqueado por defecto)
	pthread_mutex_lock(philo->fork); // Bloquea el mutex para evitar que otro hilo lo acceda (si otro hilo lo tiene bloqueado, se queda esperando a que se desbloquee)
	pthread_mutex_unlock(fork); // Desbloquea el mutex, permitiendo a otro hilo agarrarlo*/
	