/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:38:33 by aarranz-          #+#    #+#             */
/*   Updated: 2024/06/06 12:28:25 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(void	*content)
{
	t_philo	*node;

	(void)content;
	node = (t_philo *)malloc(sizeof(t_philo));
	if (!node)
		return (NULL);
	node->next = NULL;
	return (node);
}
