/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:03:30 by pramos            #+#    #+#             */
/*   Updated: 2024/01/25 12:14:00 by marvin           ###   ########.fr       */
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
	if (philo->eat < philo->data->times_eat || philo->data->dead == 0)
	{
		pthread_mutex_lock(philo->data->print);
		philo->eat += 1;
		pthread_mutex_unlock(philo->data->print);
	}
}

void	forks_down(t_data_ph *philo)
{
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

int	philo_continue(t_data_ph *philo)
{
	if (print(philo, SLEEPING))
		return (1);
	if (ft_usleep(philo, philo->data->t_2_sleep))
		return (1);
	if (print(philo, THINKING))
		return (1);
	if (ft_usleep(philo, philo->data->t_2_eat - philo->data->t_2_sleep))
		return (1);
	return (0);
}

void	*philo_start(void *ph)
{
	t_data_ph	*philo;

	philo = (t_data_ph *)ph;
	while (1)
	{
		forks_up(philo);
		if (ft_usleep(philo, philo->data->t_2_eat))
			break ;
		forks_down(philo);
		pthread_mutex_lock(philo->data->print);
		if (philo->eat == philo->data->n_ph_eat
			|| philo->data->dead >= 1)
		{
			pthread_mutex_unlock(philo->data->print);
			break ;
		}
		pthread_mutex_unlock(philo->data->print);
		if (philo_continue(philo))
			break ;
	}
	return (NULL);
}

void	init_thread(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_of_ph && data->n_of_ph > 1)
		pthread_create(&data->philosopher[i], NULL,
			&philo_start, (void *)&data->ph[i]);
	i = -1;
	while (++i < data->n_of_ph && data->n_of_ph > 1)
		pthread_join(data->philosopher[i], NULL);
}
