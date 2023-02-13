/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 01:11:41 by lmagalha          #+#    #+#             */
/*   Updated: 2023/02/11 05:00:36 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (0);
	else
		printf("Only valid numbers are accepted");
	return (1);
}

int	check_inputs(char *num[])
{
	int	i;

	i = 2;
	if (ft_atoi(num[1]) < 1)
	{
		printf("The number of philosophers must be greater than 0");
		return (1);
	}
	while (i < 5)
	{
		if (ft_atoi(num[i]) < 1)
		{
			printf("Please insert valid numbers");
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_valid_digit(char *num[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (num[i])
	{
		while (num[i][j])
		{
			if (ft_isdigit(num[i][j] == 1))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	if (check_inputs(num) == 1)
		return (1);
	return (0);
}
