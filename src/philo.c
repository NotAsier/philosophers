/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:39:36 by aarranz-          #+#    #+#             */
/*   Updated: 2024/06/11 12:32:08 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
    t_params	*params;
	t_philo		*philo;

	params = (t_params *)malloc(sizeof(t_params));
	philo = NULL;
	if(argc == 5 || argc == 6)
	{
		init_struct(params);
		parse_args(params, argv);
		create_philos(params, &philo);
		philos_threads(params, &philo);
		
	}
}

	/*pthread_t	philo->thread; // Variable hilo
	pthread_create(&philo->thread, NULL, routine, current); // Crea el hilo y ejecuta la función routine con argumento current	
	pthread_join(philo->thread, NULL); // Espera a que el hilo en si termine
	
	mutex_t		fork; // Variable mutex
	pthread_mutex_init(&fork); // Inicializa el mutex (desbloqueado por defecto)
	pthread_mutex_lock(philo->fork); // Bloquea el mutex para evitar que otro hilo lo acceda (si otro hilo lo tiene bloqueado, se queda esperando a que se desbloquee)
	pthread_mutex_unlock(fork); // Desbloquea el mutex, permitiendo a otro hilo agarrarlo*/
	