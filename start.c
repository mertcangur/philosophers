/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgur <mgur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:36:59 by mgur              #+#    #+#             */
/*   Updated: 2023/03/23 14:37:12 by mgur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_data *data, int i)
{
	pthread_mutex_lock(&data->spagetti);
	if ((int)(get_time() - data->philo[i].last_eat) >= data->die_time)
	{
		pthread_mutex_unlock(&data->spagetti);
		pthread_mutex_lock(&data->time_has_come);
		data->dead = 1;
		pthread_mutex_unlock(&data->time_has_come);
		pthread_mutex_lock(&data->printable);
		if (data->philo[i].max_eat_p != data->philo[i].eated)
			printf("%lu\t %d\t %s\n", get_time() - data->philo[i].first_eat, \
			data->philo[i].pos, "is dead");
		pthread_mutex_unlock(&data->printable);
		return (1);
	}
	return (0);
}

void	check(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		if (is_dead(data, i))
			break ;
		else
			pthread_mutex_unlock(&data->spagetti);
		i++;
		if (i == data->philo_count)
			i = 0;
		usleep(50);
	}
}

void	get_start(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_create (&data->philo[i].thread_id, NULL, \
		&routine, &data->philo[i]))
			return ;
		i += 2;
		usleep(50);
	}
	i = 1;
	while (i < data->philo_count)
	{
		pthread_create (&data->philo[i].thread_id, NULL, \
		&routine, &data->philo[i]);
		i += 2;
		usleep(50);
	}
	check(data);
}
