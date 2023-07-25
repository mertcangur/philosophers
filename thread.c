/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgur <mgur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:39:46 by mgur              #+#    #+#             */
/*   Updated: 2023/03/23 14:33:54 by mgur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_func(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->data->printable);
	pthread_mutex_lock(&(philo->data->time_has_come));
	if (!philo->data->dead)
		printf("%lu \t %d \t %s \n", get_time() - philo->first_eat, \
		philo->pos, message);
	pthread_mutex_unlock(&(philo->data->time_has_come));
	pthread_mutex_unlock(&philo->data->printable);
}

void	ft_sleep(t_philo *philo)
{
	print_func(philo, "is sleeping");
	new_sleep(philo->data->sleep_time);
	print_func(philo, "is thinking");
}

int	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left_f]);
	print_func(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->forks[philo->right_f]);
	print_func(philo, "has taken a fork");
	print_func(philo, "is eating");
	if (philo->max_eat_p != -1)
		philo->eated++;
	pthread_mutex_lock(&philo->data->spagetti);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->data->spagetti);
	new_sleep(philo->data->eat_time);
	pthread_mutex_unlock(&philo->data->forks[philo->left_f]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_f]);
	return (1);
}

void	*routine(void *params)
{
	t_philo	*philo;

	philo = (t_philo *)params;
	philo->first_eat = get_time();
	pthread_mutex_lock(&philo->data->spagetti);
	philo->last_eat = philo->first_eat;
	pthread_mutex_unlock(&philo->data->spagetti);
	while (1)
	{
		if (philo->max_eat_p != -1 && philo->eated == philo->max_eat_p)
			break ;
		ft_eating(philo);
		ft_sleep(philo);
		pthread_mutex_lock(&philo->data->time_has_come);
		if (philo->data->dead)
		{
			pthread_mutex_unlock(&philo->data->time_has_come);
			break ;
		}
		pthread_mutex_unlock(&philo->data->time_has_come);
	}
	return (NULL);
}
