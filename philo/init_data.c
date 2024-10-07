/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:49:13 by pramos            #+#    #+#             */
/*   Updated: 2024/01/30 16:56:02 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, char **av, int ac)
{
	data->start_time = get_time();
	data->n_of_ph = ft_atoi(av[1]);
	data->t_2_die = (u_int64_t) ft_atoi(av[2]);
	data->t_2_eat = (u_int64_t) ft_atoi(av[3]);
	data->t_2_sleep = (u_int64_t) ft_atoi(av[4]);
	data->times_eat = 0;
	data->dead = 0;
	data->id_ph = 0;
	if (ac == 6)
		data->n_ph_eat = ft_atoi(av[5]);
	else
		data->n_ph_eat = ft_atoi("0");
}

void	new_philo(t_data *data, int i)
{
	data->ph[i].is_awake = 0;
	data->ph[i].data = data;
	data->ph[i].id = i + 1;
	data->ph[i].eat = 0;
	if (i == 0)
	{
		data->ph[i].fork_left = &data->forks[i];
		data->ph[i].fork_right = &data->forks[data->n_of_ph - 1];
	}
	else
	{
		data->ph[i].fork_left = &data->forks[i - 1];
		data->ph[i].fork_right = &data->forks[i];
	}
}

void	init_philo(t_data *data)
{
	int	i;

	i = -1;
	data->ph = malloc(sizeof(t_data_ph) * data->n_of_ph);
	data->philosopher = malloc(sizeof(pthread_t) * data->n_of_ph);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_of_ph);
	data->wait = malloc(sizeof(pthread_mutex_t));
	data->print = malloc(sizeof(pthread_mutex_t));
	while (++i < data->n_of_ph)
	{
		new_philo(data, i);
		pthread_mutex_init(&data->forks[i], NULL);
	}
	pthread_mutex_init(data->wait, NULL);
	pthread_mutex_init(data->print, NULL);
	if (data->n_of_ph == 1)
	{
		pthread_mutex_lock(data->ph->fork_left);
		printf("there's only 1 fork philo 1 DIED");
		pthread_mutex_unlock(data->ph->fork_left);
	}
	if (data->n_ph_eat == 0)
		data->n_ph_eat = -1;
}

int	check_errors( char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	if (ac > 6 || ac < 5)
		return (printf("Many/missing armguments\n"), 0);
	while (av[i] != NULL)
	{
		if (!ft_atoi(av[i]))
			return (printf("Only numbers\n"), 0);
		j = 0;
		while (av[i][j] != 0)
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (printf("Only positive numbers\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

void	init(t_data *data, char **av, int ac)
{
	if (!check_errors(av, ac))
		return ;
	init_data(data, av, ac);
	init_philo(data);
	init_thread(data);
	finish_thread(data);
}
