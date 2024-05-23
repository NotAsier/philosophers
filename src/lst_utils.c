/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:38:33 by aarranz-          #+#    #+#             */
/*   Updated: 2024/05/23 15:06:41 by aarranz-         ###   ########.fr       */
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

t_philo	*ft_lstlast(t_philo *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_front(t_philo **lst, t_philo *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*node;

	if (lst && new)
	{
		node = ft_lstlast(*lst);
		if (node)
			node->next = new;
		else
			ft_lstadd_front(lst, new);
	}
}