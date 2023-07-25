/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgur <mgur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:13:35 by mgur              #+#    #+#             */
/*   Updated: 2023/03/24 01:07:49 by mgur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_philo
{
	int				pos;
	int				left_f;
	int				right_f;
	int				eated;
	int				max_eat_p;
	unsigned long	last_eat;
	unsigned long	first_eat;
	pthread_t		thread_id;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				philo_count;
	int				eat_time;
	int				die_time;
	int				sleep_time;
	int				max_eat;
	int				dead;
	t_philo			*philo;
	pthread_mutex_t	printable;
	pthread_mutex_t	*forks;
	pthread_mutex_t	spagetti;
	pthread_mutex_t	time_has_come;
}	t_data;

int				ft_init_data(t_data *data, int argc, char **argv);
int				check_arg(int argc, char **argv);
int				ft_control(t_data *data);
int				ft_init_philo(t_data *data);
int				mutex_init(t_data *data);
int				ft_init_philo(t_data *data);
int				is_all_digit(char *str);
int				is_digit(int c);
int				ft_atoi(const char *str);
void			new_sleep(unsigned long duration);
void			*routine(void *params);
void			get_start(t_data *data);
unsigned long	get_time(void);

#endif
