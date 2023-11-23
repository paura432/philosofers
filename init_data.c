/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:49:13 by pramos            #+#    #+#             */
/*   Updated: 2023/11/23 22:04:30 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, char **av, int ac)
{
	data->n_of_ph = (int) ft_atoi(av[1]);
	data->t_2_die = (u_int64_t) ft_atoi(av[2]);
	data->t_2_eat = (u_int64_t) ft_atoi(av[3]);
	data->t_2_sleep = (u_int64_t) ft_atoi(av[4]);
	if(ac == 6)
		data->n_ph_eat = ft_atoi(av[5]);
}

void	init_philo(t_data *data, t_data_ph **philo_list)
{
	int i;
	t_data_ph *current = NULL;
	i = 0;

    while (i < data->n_of_ph) {
        // Crear un nuevo nodo para el filósofo
        t_data_ph *new_philo = malloc(sizeof(t_data_ph));
        if (!new_philo) {
            // Manejar el error de asignación de memoria si es necesario
            exit(EXIT_FAILURE);
        }

        // Inicializar los campos del nuevo nodo
        new_philo->id = i;
        new_philo->t_2_die = data->t_2_die;
        new_philo->t_eating = 0;
        new_philo->t_sleeping = 0;
        new_philo->t_thinking = 0;
        new_philo->next = NULL;

        // Agregar el nuevo nodo a la lista enlazada
        if (!current) {
            // Si es el primer nodo, actualiza el puntero de inicio
            *philo_list = new_philo;
            current = *philo_list;
        } else {
            // Si no es el primer nodo, enlaza el nodo actual al nuevo nodo
            current->next = new_philo;
            current = new_philo;
        }

        i++;
    }
}
// 	int i;

// 	i = data->n_of_ph;
// 	t_data_ph *new_philo;
// 	while(i > 0)
// 	{
// 		new_philo = malloc(sizeof(t_data_ph));
// 		new_philo->id = i + 1;
// 		new_philo->t_2_die = data->t_2_die;
// 		new_philo->t_eating = 0;
// 		new_philo->t_sleeping = 0;
// 		new_philo->t_thinking = 0;
// 		*philo = new_philo;
// 		printf("ph = %i\n", (*philo)->id);
// 		(*philo) = (*philo)->next;

// 		i--;
// 	}
// }

void	init(t_data *data, t_data_ph *philo, char **av, int ac)
{
	init_data(data, av, ac);
	init_philo(data, &philo);
}
