/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:49:13 by pramos            #+#    #+#             */
/*   Updated: 2023/12/05 21:11:19 by pramos           ###   ########.fr       */
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
	if(ac == 6)
		data->n_ph_eat = ft_atoi(av[5]);
}

void	new_philo(t_data *data, int i)
{
	data->ph[i].is_awake = 0;
	data->ph[i].data = data;
	data->ph[i].id = i + 1;
	data->ph[i].fork_right = &data->forks[i];
	if(i + 1 != data->n_of_ph)
		data->ph[i].fork_left = &data->forks[i + 1];
	else
		data->ph[i].fork_left = &data->forks[0];
	data->ph[i].wait = malloc(sizeof(pthread_mutex_t));
}

void	init_philo(t_data *data)
{
	int i;

	i = -1;
	data->ph = malloc(sizeof(t_data_ph) * data->n_of_ph);
	data->philosopher = malloc(sizeof(pthread_t) * data->n_of_ph);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_of_ph);

	while(++i < data->n_of_ph)
	{
		new_philo(data, i);
		pthread_mutex_init(&data->forks[i], NULL);
	}
}

void	init(t_data *data, char **av, int ac)
{
	init_data(data, av, ac);
	init_philo(data);
	init_thread(data);
}
