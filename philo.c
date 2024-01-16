/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:06:05 by pramos            #+#    #+#             */
/*   Updated: 2024/01/09 21:03:13 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_data_ph *philo, char *message)
{
	pthread_mutex_lock(philo->data->print);
	u_int64_t	time;

	time = philo->data->start_time;
	if (philo->data->dead == 0)
		printf("%llu ms %i %s\n", (get_time() - time), philo->id, message);
	else if (message == DIED && philo->data->dead == 1)
		printf("%llu ms %i %s\n", (get_time() - time), philo->id, message);
	pthread_mutex_unlock(philo->data->print);
}

// void	leaks(void)
// {
// 	system("leaks -q philo");
// }

int	main(int ac, char **av)
{
	t_data	data;

	init(&data, av, ac);
	return (0);
}
