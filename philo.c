/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:06:05 by pramos            #+#    #+#             */
/*   Updated: 2024/01/22 12:28:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_data_ph *philo, char *message)
{
	if(philo->data->dead > 1)
		return ;
	pthread_mutex_lock(philo->data->print);
	u_int64_t	time;

	time = philo->data->start_time;
	printf("%lu ms %i %s\n", (get_time() - time), philo->id, message);
	pthread_mutex_unlock(philo->data->print);
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
