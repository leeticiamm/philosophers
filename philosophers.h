/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:36:14 by lmagalha          #+#    #+#             */
/*   Updated: 2023/02/13 04:46:50 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/type.h>

typedef struct	s_philo
{
	int		id;
	int		right_hand;
	int		left_hand;
	long		last_meal;
	int		count_meals;
	pthread_t	thread_id;
	struct s_data	*data;
}			t_philo;

typedef struct s_data
{
	t_philo		*philo
	pthread_mutex_t	*forks
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	int		num_philos;
	int		must_eat;
	long		start_time;
}			t_data;

int	is_valid_digit(char *num[]);

#endif
