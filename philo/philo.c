/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:06:05 by pramos            #+#    #+#             */
/*   Updated: 2024/01/30 16:58:32 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print(t_data_ph *philo, char *message)
{
	u_int64_t	time;

	pthread_mutex_lock(philo->data->print);
	time = philo->data->start_time;
	if ((philo->data->dead == 1
			|| philo->data->times_eat == philo->data->n_ph_eat)
		&& philo->data->id_ph != philo->id)
	{
		pthread_mutex_unlock(philo->data->print);
		return (1);
	}
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
