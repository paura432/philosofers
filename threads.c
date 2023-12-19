/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:03:30 by pramos            #+#    #+#             */
/*   Updated: 2023/12/19 21:51:26 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_up(t_data_ph *philo)
{
	pthread_mutex_lock(philo->fork_right);
	pthread_mutex_lock(philo->fork_left);

	print(philo, fork_up);
	print(philo, fork_up);
	print(philo, eating);
	philo->t_4_dead = get_time();
	if(philo->id == philo->data->n_of_ph)
		philo->data->times_eat += 1;
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
		printf("%llu ms %i %s\n", (get_time() - philo->data->start_time), philo->id, message);
	pthread_mutex_unlock(philo->data->print);
}

void	*philo_start(void *ph)
{
	t_data_ph *philo;

	philo = (t_data_ph *)ph;
	if(philo->id % 2 == 0)
		usleep(10);
	while(philo->data->dead == 0)
	{
		forks_up(philo);
		ft_usleep(philo, philo->data->t_2_eat);
		forks_down(philo);
		print(philo, sleeping);
		ft_usleep(philo, philo->data->t_2_sleep);
		print(philo, thinking);
		if(philo->data->times_eat == philo->data->n_ph_eat)
			break;
	}
	return NULL;
}

void	init_thread(t_data *data)
{
	int i;

	i = -1;
	while(++i < data->n_of_ph && data->n_of_ph > 1)
		pthread_create(&data->philosopher[i], NULL, &philo_start, (void *)&data->ph[i]);
	i = -1;
	while(++i < data->n_of_ph && data->n_of_ph > 1)
		pthread_join(data->philosopher[i], NULL);
}
