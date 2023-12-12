/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:03:30 by pramos            #+#    #+#             */
/*   Updated: 2023/12/12 21:10:21 by pramos           ###   ########.fr       */
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
void	forks_up(t_data_ph *philo)
{
	// printf("id :: %i\n", philo->id);
	pthread_mutex_lock(philo->fork_right);
	print(philo, fork_up);
	pthread_mutex_lock(philo->fork_left);
	print(philo, fork_up);
	philo->t_4_dead = get_time();
	print(philo, eating);
	philo->times_eat += 1;
}

void	forks_down(t_data_ph *philo)
{
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
}

void	free_threads(t_data_ph *philo)
{
	free(philo->data->ph);
	free(philo->data->philosopher);
	free(philo->data->forks);
	free(philo->data->print);
}
void	print(t_data_ph *philo, char *message)
{
	pthread_mutex_lock(philo->data->print);
	if(philo->data->dead == 0)
		printf("%llu ms %i %s\n", (get_time() - philo->data->start_time), philo->id, message);
	else if(message == died && philo->data->dead == 1)
	{
		// free_threads(philo);
		printf("%llu ms %i %s\n", (get_time() - philo->data->start_time), philo->id, message);
		exit(EXIT_FAILURE);
	}
	pthread_mutex_unlock(philo->data->print);
}

void	*philo_start(void *ph)
{
	t_data_ph *philo;

	philo = (t_data_ph *)ph;
	if(philo->id % 2 == 0)
		usleep(50);
	while(philo->data->dead == 0)
	{
		if(philo->data->dead == 0)
			eat(philo);
		if(philo->data->dead == 0)
			slep(philo);
		if(philo->data->dead == 0)
			think(philo);
		if(philo->times_eat == philo->data->n_ph_eat)
			break;
	}
	return NULL;
}

void	init_thread(t_data *data)
{
	int i;

	i = -1;
	while(++i < data->n_of_ph)
		pthread_create(&data->philosopher[i], NULL, &philo_start, (void *)&data->ph[i]);

	i = -1;
	while(++i < data->n_of_ph)
		pthread_join(data->philosopher[i], NULL);
}
