/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgur <mgur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:33:11 by mgur              #+#    #+#             */
/*   Updated: 2023/03/24 01:21:14 by mgur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_clear(t_data *data)
{
	if (data->philo)
		free(data->philo);
	pthread_mutex_destroy(&data->spagetti);
	pthread_mutex_destroy(&data->printable);
	pthread_mutex_destroy(&data->time_has_come);
}

int	ft_control(t_data *data)
{
	data->philo->last_eat = get_time();
	if (data->philo_count == 1)
	{
		printf ("%ld %d has taken a fork\n", \
		get_time() - data->philo->last_eat, data->philo->pos);
		new_sleep (data->die_time);
		printf ("%ld %d died\n", get_time() - \
		data->philo->last_eat, data->philo->pos);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (check_arg(argc, argv) || \
	ft_init_data(&data, argc, argv) || ft_init_philo(&data))
	{
		printf("wrong input\n");
		return (1);
	}
	if (ft_control(&data))
		return (0);
	get_start(&data);
	i = 0;
	while (i < data.philo_count)
	{
		if (pthread_join(data.philo[i].thread_id, NULL) != 0)
			return (1);
		i++;
	}
	ft_clear(&data);
}
