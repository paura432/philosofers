/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:03:30 by pramos            #+#    #+#             */
/*   Updated: 2023/12/05 21:15:55 by pramos           ###   ########.fr       */
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
	printf("%llu ms %i FORK_UP\n", (get_time() - philo->data->start_time), philo->id);
	pthread_mutex_lock(philo->fork_left);
	printf("%llu ms %i FORK_UP\n", (get_time() - philo->data->start_time), philo->id);
	printf("%llu ms %i is eating\n", (get_time() - philo->data->start_time), philo->id);
	philo->t_4_dead = get_time();
}

void	forks_down(t_data_ph *philo)
{
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
}


void	*philo_start(void *ph)
{
	int i;
	t_data_ph *philo;

	i = -1;
	philo = (t_data_ph *)ph;
	if(philo->id % 2 == 0)
		usleep(50);
	while(1)
	{
		forks_up(philo);
		usleep(philo->data->t_2_eat * 1000);
		printf("tiempo pa morir%llu ms\n", (get_time() - philo->t_4_dead));
		if((get_time() - philo->t_4_dead) >= philo->data->t_2_die)
		{
			printf("%llu ms %i is dead\n", (get_time() - philo->data->start_time), philo->id);
			break;
		}
		forks_down(philo);
		printf("%llu ms %i is sleeping\n", (get_time() - philo->data->start_time), philo->id);
		while(1)
		{
			if((get_time() - philo->t_4_dead) >= philo->data->t_2_die)
			{
				printf("tiempo pa morir%llu ms\n", (get_time() - philo->t_4_dead));
				printf("%llu ms %i is dead\n", (get_time() - philo->data->start_time), philo->id);
				break;
			}
			if(usleep(philo->data->t_2_sleep * 1000) == 0)
			{
				philo->is_awake = 1;
				break;
			}
		}
		if(philo->is_awake == 1)
		{
			printf("%llu ms %i is thinking\n", (get_time() - philo->data->start_time), philo->id);
			philo->is_awake = 0;
		}
	}

	return NULL;
}

	// while(++i < philo->data->n_ph_eat)
	// {
	// 	if(philo->id % 2 == 0)
	// 		usleep(50);
	// 	forks_up(philo);
	// 	printf("%li %i FORK_UP\n", (get_time() - philo->data->start_time), philo->id);
	// 	forks_down(philo);
	// 	printf("%li %i is sleeping\n", (get_time() - philo->data->start_time), philo->id);
	// 	usleep(philo->data->t_2_die);
	// 	printf("%li %i is thinking\n", (get_time() - philo->data->start_time), philo->id);
	// }

void	init_thread(t_data *data)
{
	int i;

	i = -1;
	while(++i < data->n_of_ph)
	{
		pthread_create(&data->philosopher[i], NULL, &philo_start, (void *)&data->ph[i]);

	}

	i = -1;
	while(++i < data->n_of_ph)
		pthread_join(data->philosopher[i], NULL);
}
