/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:36:58 by lmagalha          #+#    #+#             */
/*   Updated: 2023/02/27 11:45:38 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philos(t_data *data, char *argv[])
{
	int		i;
	long	last_meal;

	i = -1;
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	last_meal = get_time();
	if (argv[5])
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	data->philo = malloc(sizeof(t_philo) * data->num_philos);
	while (++i < data->num_philos)
	{
		data->philo[i].id = i + 1;
		data->philo[i].left_hand = i;
		data->philo[i].right_hand = (i + 1) % data->num_philos;
		data->philo[i].count_meals = 0;
		data->philo[i].last_meal = last_meal;
		data->philo[i].data = data;
		data->philo[i].satisfied = 0;
	}
	init_forks(data);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (is_valid_digit(argv) == 1)
			return (0);
		if (argc == 6 && ft_atoi(argv[5]) < 1)
		{
			printf("Please insert valid numbers\n");
			return (0);
		}
		data.start_time = get_time();
		data.is_dead = 0;
		data.finish_meal = 0;
		init_philos(&data, argv);
		init_thread(&data);
		destroy_forks(&data);
		free(data.philo);
	}
	else
		printf("Invalid number of arguments\n");
	return (0);
}
