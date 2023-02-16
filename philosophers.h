/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:36:14 by lmagalha          #+#    #+#             */
/*   Updated: 2023/02/16 17:47:45 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				right_hand;
	int				left_hand;
	long			last_meal;
	int				count_meals;
	pthread_t		thread_id;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	check;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				num_philos;
	int				must_eat;
	long			start_time;
	int				is_dead;
	int				finish_meal;
}					t_data;

int					is_valid_digit(char *num[]);
int					ft_atoi(const char *str);
void				init_forks(t_data *data);
void				destroy_forks(t_data *data);
long				get_time(void);
void				init_thread(t_data *data);
void				printing(t_data *data, t_philo *philo, char print);
int					check_death(t_data *data, t_philo *philo);
void				smart_sleep(t_data *data, t_philo *philo, long time);
int					check_must_eat(t_data *data, t_philo *philo);

#endif
