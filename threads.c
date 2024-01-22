/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:03:30 by pramos            #+#    #+#             */
/*   Updated: 2024/01/22 12:26:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_up(t_data_ph *philo)
{
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(philo->fork_right);
	print(philo, FORK_UP);
	print(philo, FORK_UP);
	print(philo, EATING);
	philo->t_4_dead = get_time();
	if (philo->id == philo->data->n_of_ph)
	{
		pthread_mutex_lock(philo->data->wait);
		philo->data->times_eat += 1;
		pthread_mutex_unlock(philo->data->wait);
	}
}

void	forks_down(t_data_ph *philo)
{
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

void	free_threads(t_data_ph *philo)
{
	free(philo->data->ph);
	free(philo->data->philosopher);
	free(philo->data->forks);
	free(philo->data->wait);
	free(philo->data->print);
}

void	*philo_start(void *ph)
{
	t_data_ph *philo;

	philo = (t_data_ph *)ph;
	while (philo->data->dead < 1)
	{
		forks_up(philo);
		ft_usleep(philo, philo->data->t_2_eat);
		forks_down(philo);
		print(philo, SLEEPING);
		ft_usleep(philo, philo->data->t_2_sleep);
		print(philo, THINKING);
		pthread_mutex_lock(philo->data->wait);
		if(philo->data->times_eat == philo->data->n_ph_eat)
		{
			pthread_mutex_unlock(philo->data->wait);
			break;
		}
		pthread_mutex_unlock(philo->data->wait);
	}
	return NULL;
}

void	init_thread(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->n_of_ph && data->n_of_ph > 1)
		pthread_create(&data->philosopher[i], NULL, &philo_start, (void *)&data->ph[i]);
	i = -1;
	while (++i < data->n_of_ph && data->n_of_ph > 1)
		pthread_join(data->philosopher[i], NULL);
	
}
