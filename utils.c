/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:53:59 by pramos            #+#    #+#             */
/*   Updated: 2024/01/25 12:15:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi(char *str)
{
	int		i;
	long	a;
	int		signo;

	a = 0;
	signo = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
	{
		signo = -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	while (str[i] > 47 && str[i] < 58)
		a = a * 10 + (str[i++] - '0');
	return (a * signo);
}

u_int64_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		perror("Error in gettimeofday");
		return (0);
	}
	return ((time.tv_sec * (u_int64_t)1000) + (time.tv_usec / 1000));
}

int	ft_usleep(t_data_ph *philo, u_int64_t time)
{
	u_int64_t	slep_2;

	slep_2 = get_time();
	while (get_time() - slep_2 < time && philo)
	{
		usleep(100);
		if (get_time() - philo->t_4_dead > philo->data->t_2_die)
		{
			pthread_mutex_lock(philo->data->print);
			if (philo->data->dead == 0)
			{
				philo->data->dead += 1;
				pthread_mutex_unlock(philo->data->print);
				print(philo, DIED);
				return (1);
			}
			pthread_mutex_unlock(philo->data->print);
			return (1);
		}
	}
	return (0);
}

void	finish_thread(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_of_ph)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(data->wait);
	free(data->ph);
	free(data->philosopher);
	free(data->forks);
	free(data->wait);
	free(data->print);
}
