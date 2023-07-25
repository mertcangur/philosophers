/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgur <mgur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:44:00 by mgur              #+#    #+#             */
/*   Updated: 2023/03/24 01:07:26 by mgur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_digit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	else
		return (0);
}

int	is_all_digit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	result;
	int		sing;

	i = 0;
	sing = 1;
	result = 0;
	while (str[i] && (str[i] == 32 || (str[i] >= '\t' && str[i] <= '\r')))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sing *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		result = (str[i] - 48) + (result * 10);
		if (result > 2147483647 && sing == 1)
			return (-1);
		else if (result > 2147483648 && sing == -1)
			return (-1);
		i++;
	}
	return (sing * result);
}

void	new_sleep(unsigned long duration)
{
	unsigned long	start;

	start = get_time();
	while (1)
	{
		if (get_time() - start >= duration)
			break ;
		usleep(50);
	}
}
