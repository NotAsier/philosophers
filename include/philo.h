/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:18:49 by aarranz-          #+#    #+#             */
/*   Updated: 2024/06/10 13:44:28 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_params
{
	int		philo_count;
    int     die;
   	int		eat;
    int		sleep;
    int     eat_count;
	long	start;
}			t_params;

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	pthread_mutex_t		fork;
	struct s_params		*params;
	struct s_philo		*next;
}			t_philo;

int			philo_atoi(char *str);
void		create_philos(t_params *params, t_philo **philo);
void		init_struct(t_params *params);
void		parse_args(t_params *params, char **argv);
void    	philos_threads(t_params *params, t_philo  **philo);
t_philo		*ft_lstnew(void	*content);
void		*routine(void *arg);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
long		ft_time(void);
void		ft_usleep(unsigned int ms);
void    	print_p(t_philo *philo, int id);

#endif // PHILOSOPHERS_H