/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:20:43 by lmagalha          #+#    #+#             */
/*   Updated: 2023/02/16 17:55:57 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	one_philo(t_data *data)
{
	pthread_mutex_lock(&(data->forks[0]));
	printf("%ldms\t1\thas taken a fork\n", (get_time() - data->start_time));
	usleep(data->time_to_die * 1000);
	pthread_mutex_unlock(&(data->forks[0]));
}

void	eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->forks[philo->left_hand]));
	printing(data, philo, 'f');
	if (check_death(data, philo) == 1 || check_must_eat(data, philo) == 1)
	{
		pthread_mutex_unlock(&(data->forks[philo->left_hand]));
		return ;
	}
	pthread_mutex_lock(&(data->forks[philo->right_hand]));
	printing(data, philo, 'f');
	if (check_death(data, philo) == 1 || check_must_eat(data, philo) == 1)
	{
		pthread_mutex_unlock(&(data->forks[philo->left_hand]));
		pthread_mutex_unlock(&(data->forks[philo->right_hand]));
		return ;
	}
	printing(data, philo, 'e');
	philo->last_meal = get_time();
	smart_sleep(data, philo, data->time_to_eat);
	philo->count_meals++;
	pthread_mutex_unlock(&(data->forks[philo->left_hand]));
	pthread_mutex_unlock(&(data->forks[philo->right_hand]));
}

void	living(t_data *data, t_philo *philo)
{
	if (check_death(data, philo) == 1)
		return ;
	eat(data, philo);
	if (check_death(data, philo) == 1)
		return ;
	printing(data, philo, 's');
	smart_sleep(data, philo, data->time_to_sleep);
	printing(data, philo, 't');
	if (check_death(data, philo) == 1)
		return ;
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (data->num_philos == 1)
		one_philo(data);
	else
	{
		if (philo->id % 2 == 0)
			usleep(400);
		while (42)
		{
			living(data, philo);
			if (check_death(data, philo) == 1 || check_must_eat(data,
					philo) == 1)
				break ;
		}
	}
	return (0);
}

void	init_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_create(&(data->philo[i].thread_id), NULL, &routine,
			&(data->philo[i]));
		i++;
	}
	while (42)
	{
		i = -1;
		while (++i < data->num_philos)
			check_death(data, &data->philo[i]);
		if (check_death(data, data->philo) == 1 || check_must_eat(data,
				data->philo) == 1)
			break ;
	}
	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(data->philo[i].thread_id, NULL);
		i++;
	}
}
