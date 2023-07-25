/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgur <mgur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:33:04 by mgur              #+#    #+#             */
/*   Updated: 2023/03/23 14:07:25 by mgur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (1);
	while (i < argc)
	{
		if (is_all_digit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_init_data(t_data *data, int argc, char **argv)
{
	data->philo_count = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->dead = 0;
	data->max_eat = 0;
	if (argc == 6)
		data->max_eat = ft_atoi(argv[5]);
	if (data->philo_count < 1 || data->philo_count > 256 || data->die_time < 0 \
	|| data->eat_time < 0 || data->sleep_time < 0 || data->max_eat < 0)
		return (1);
	if (argc == 5)
		data->max_eat = -1;
	data->philo = malloc(sizeof(t_philo) * data->philo_count);
	return (0);
}

int	mutex_init(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->printable, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->spagetti, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->time_has_come, NULL) != 0)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		return (1);
	while (i < data->philo_count)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		data->philo[i].pos = i + 1;
		data->philo[i].eated = 0;
		data->philo[i].last_eat = 0;
		data->philo[i].left_f = i;
		data->philo[i].right_f = (i + 1) % data->philo_count;
		data->philo[i].data = data;
		data->philo[i].max_eat_p = data->max_eat;
		i++;
	}
	if (mutex_init(data))
		return (1);
	return (0);
}
