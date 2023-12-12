/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_things.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:00:23 by pramos            #+#    #+#             */
/*   Updated: 2023/12/12 20:58:32 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_data_ph *philo)
{
	forks_up(philo);
	while(philo->data->dead == 0)
	{
		if((get_time() - philo->t_4_dead) >= philo->data->t_2_die)
		{
			philo->data->dead = 1;
			print(philo, died);
			break ;
		}
		if(usleep(philo->data->t_2_eat * 1000) == 0 && philo->data->dead == 0)
		{
			forks_down(philo);
			print(philo, sleeping);
			break ;
		}
	}
}

void	slep(t_data_ph *philo)
{
	while(philo->data->dead == 0)
	{
		if((get_time() - philo->t_4_dead) >= philo->data->t_2_die)
		{
			philo->data->dead = 1;
			print(philo, died);
			break ;
		}
		if(usleep(philo->data->t_2_sleep * 1000) == 0)
		{
			philo->is_awake = 1;
			break;
		}
	}
}

void	think(t_data_ph *philo)
{
	if((get_time() - philo->t_4_dead) >= philo->data->t_2_die)
	{
		philo->data->dead = 1;
		print(philo, died);
	}
	if(philo->is_awake == 1)
	{
		print(philo, thinking);
		philo->is_awake = 0;
	}
}
