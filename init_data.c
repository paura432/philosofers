/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:49:13 by pramos            #+#    #+#             */
/*   Updated: 2023/11/27 20:08:22 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, char **av, int ac)
{
	data->n_of_ph = ft_atoi(av[1]);
	return ;
	data->t_2_die = (u_int64_t) ft_atoi(av[2]);
	data->t_2_eat = (u_int64_t) ft_atoi(av[3]);
	data->t_2_sleep = (u_int64_t) ft_atoi(av[4]);
	if(ac == 6)
		data->n_ph_eat = ft_atoi(av[5]);
}

t_data_ph	*new_philo(t_data *data, int i)
{
	t_data_ph *new_philo;

	new_philo = malloc(sizeof(t_data_ph));
	new_philo->ph = malloc(sizeof(pthread_t));
	
	new_philo->id = i + 1;
	new_philo->t_2_die = data->t_2_die;
	new_philo->t_eating = 0;
	new_philo->t_sleeping = 0;
	new_philo->t_thinking = 0;
	new_philo->next = NULL;

	return(new_philo);
}

void	init_philo(t_data *data, t_data_ph **philo_list)
{
	int i;

	i = 0;
	while(i < data->n_of_ph)
	{
		lstadd_back(philo_list, new_philo(data, i));
		i++;
	}
}

void	init(t_data *data, t_data_ph **philo, char **av, int ac)
{
	init_data(data, av, ac);
	init_philo(data, philo);
}
