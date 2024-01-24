/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:06:05 by pramos            #+#    #+#             */
/*   Updated: 2024/01/24 12:18:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print(t_data_ph *philo, char *message)
{
	
	pthread_mutex_lock(philo->data->print);
	if(philo->data->dead > 1 || philo->data->times_eat == philo->data->n_ph_eat)
	{
		pthread_mutex_unlock(philo->data->print);
		return (1);
	}
	if(philo->data->dead == 1)
		philo->data->dead += 1;
	u_int64_t	time;

	time = philo->data->start_time;
	printf("%lu ms %i %s\n", (get_time() - time), philo->id, message);
	pthread_mutex_unlock(philo->data->print);
	return (0);
}

void	leaks(void)
{
	system("leaks -q philo");
}

int	main(int ac, char **av)
{
	t_data	data;

	init(&data, av, ac);
	return (0);
}
