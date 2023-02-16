/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:28:42 by lmagalha          #+#    #+#             */
/*   Updated: 2023/02/16 17:57:05 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_death(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->check);
	if (data->is_dead == 1)
	{
		pthread_mutex_unlock(&data->check);
		return (1);
	}
	else if (data->time_to_die > (get_time() - philo->last_meal))
	{
		pthread_mutex_unlock(&data->check);
		return (0);
	}
	else
	{
		data->is_dead = 1;
		usleep(100);
		printf("%ldms\t%d\tdied\n", (get_time() - data->start_time), philo->id);
		pthread_mutex_unlock(&data->check);
		return (1);
	}
}

int	check_must_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->check);
	if (data->finish_meal == data->num_philos)
	{
		pthread_mutex_unlock(&data->check);
		return (1);
	}
	else if (philo->count_meals == data->must_eat)
		data->finish_meal++;
	pthread_mutex_unlock(&data->check);
	return (0);
}

void	printing(t_data *data, t_philo *philo, char print)
{
	pthread_mutex_lock(&data->print);
	if (print == 'f' && data->is_dead == 0)
		printf("%ldms\t%d\thas taken a fork\n", (get_time() - data->start_time),
			philo->id);
	else if (print == 'e' && data->is_dead == 0)
		printf("%ldms\t%d\tis eating\n", (get_time() - data->start_time),
			philo->id);
	else if (print == 's' && data->is_dead == 0)
		printf("%ldms\t%d\tis sleeping\n", (get_time() - data->start_time),
			philo->id);
	else if (print == 't' && data->is_dead == 0)
		printf("%ldms\t%d\tis thinking\n", (get_time() - data->start_time),
			philo->id);
	pthread_mutex_unlock(&data->print);
}

long	get_time(void)
{
	struct timeval	time;
	long			current_time;

	gettimeofday(&time, NULL);
	current_time = time.tv_sec * 1000;
	current_time += time.tv_usec / 1000;
	return (current_time);
}

void	smart_sleep(t_data *data, t_philo *philo, long time)
{
	long	start;
	long	now;

	start = get_time();
	now = start;
	while (now - start < time)
	{
		now = get_time();
		usleep(400);
		if (check_death(data, philo) == 1)
			break ;
	}
}
