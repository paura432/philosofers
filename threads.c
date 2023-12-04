/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:03:30 by pramos            #+#    #+#             */
/*   Updated: 2023/12/04 21:03:16 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	*thread_create(void *data)
// {
// 	t_data_ph *new_philo = (t_data_ph *)data;
// 	pthread_mutex_lock(new_philo->ph_mutex);


// 	pthread_mutex_unlock(new_philo->ph_mutex);
// 	return(0);
// }

// void	init_thread(t_data_ph **philo)
// {
// 	pthread_create((*philo)->ph, NULL, thread_create, (void *) (*philo));
// 	pthread_join(*(*philo)->ph, NULL);
// }

void	*thread_create(void *ph)
{
	t_data_ph *philo;
	long int actual_time;
	philo = (t_data_ph *)ph;
	pthread_mutex_lock(philo->data->wait);
	actual_time = get_time();

	printf("id :: %i segundo :: %li\n", philo->id, (get_time() - philo->data->start_time));

	while(get_time() - philo->data->start_time) <= philo->data->t_2_eat )
		pthread_mutex_unlock(philo->data->wait);
	return NULL;
}



void	init_thread(t_data *data)
{
	int i;

	i = -1;
	while(++i < data->n_of_ph)
		pthread_create(&data->philosopher[i], NULL, &thread_create, (void *)&data->ph[i]);
	i = -1;
	while(++i < data->n_of_ph)
		pthread_join(data->philosopher[i], NULL);
}
