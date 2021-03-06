/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:41:36 by cproesch          #+#    #+#             */
/*   Updated: 2021/12/02 13:01:38 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_ph)
	{
		if (pthread_mutex_destroy(&(data->fork[i])))
			return (0);
		i++;
	}
	if (pthread_mutex_destroy(&(data->mute_stop)))
		return (0);
	return (1);
}

void	ft_free(t_data **data)
{
	if (*data)
	{
		if ((*data)->philo)
		{
			free ((*data)->philo);
			(*data)->philo = NULL;
		}
		if ((*data)->fork)
		{
			free ((*data)->fork);
			(*data)->fork = NULL;
		}
		free ((*data));
		(*data) = NULL;
	}
	return ;
}
