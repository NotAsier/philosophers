/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:18:49 by aarranz-          #+#    #+#             */
/*   Updated: 2024/05/23 15:03:16 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_params
{
	int		philo_count;
    int     die;
    int		eat;
    int		sleep;
    int     eat_count;
}			t_params;

typedef struct s_philo
{
	int		id;
	struct s_philo	*next;
}			t_philo;

int			philo_atoi(char *str);
void		create_philos(t_params *params, t_philo *philo);
void		init_struct(t_params *params);
void		parse_args(t_params *params, char **argv);
t_philo		*ft_lstnew(void	*content);
t_philo		*ft_lstlast(t_philo *lst);
void		ft_lstadd_front(t_philo **lst, t_philo *new);
void		ft_lstadd_back(t_philo **lst, t_philo *new);

#endif // PHILOSOPHERS_H