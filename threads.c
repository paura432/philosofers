/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:03:30 by pramos            #+#    #+#             */
/*   Updated: 2023/11/28 22:15:06 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_create(void	*philo)
{
	t_data_ph *new_philo = (t_data_ph *)philo;
	pthread_mutex_lock(new_philo->ph_mutex);

	printf("id del primer hilo :: %i\n", new_philo->id);

	pthread_mutex_unlock(new_philo->ph_mutex);
}


void	init_thread(t_data_ph **philo)
{
	pthread_create(&(*philo)->ph, NULL, thread_create, (void *)&philo);

	pthread_join(&(*philo)->ph, NULL);
}
