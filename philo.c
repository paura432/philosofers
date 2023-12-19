/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:06:05 by pramos            #+#    #+#             */
/*   Updated: 2023/12/19 22:07:42 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_list(t_data *data)
{
	int i;

	i = 0;
	while(i < data->n_of_ph)
	{
		printf("id :: %i\n", data->ph[i].id);
		i++;
	}
}

// void	leaks(void)
// {
// 	system("leaks -q philo");
// }

int main(int ac, char **av)
{
	t_data data;

	init(&data, av, ac);
    return (0);
}

