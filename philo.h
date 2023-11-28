/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:06:36 by pramos            #+#    #+#             */
/*   Updated: 2023/11/28 22:11:06 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
# include <sys/time.h>

//	philo_msg
# define TAKE_FORKS "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"

//data of the philosopher
typedef struct s_data_ph
{
	int					id;
	int					t_eating;
	int					t_sleeping;
	int					t_thinking;
	int					t_2_die;
	pthread_t			*ph;
	pthread_mutex_t		*ph_mutex;
	struct s_data_ph	*next;
} t_data_ph;

//initial_data
typedef struct s_data
{
	int 			n_of_ph;
	u_int64_t 		t_2_die;
	u_int64_t 		t_2_eat;
	u_int64_t 		t_2_sleep;
	int 			n_ph_eat;
} t_data;

//list
t_data_ph	*lstlast(t_data_ph *lst);
void		lstadd_back(t_data_ph **lst, t_data_ph *new);

//init_data
void		init(t_data *data, t_data_ph **philo, char **av, int ac);
void		init_data(t_data *data, char **argv, int ac);
void		init_philo(t_data *data, t_data_ph **philo_list);
t_data_ph	*new_philo(t_data *data, int i);

//utils
long 	ft_atoi(char *str);

//threads
void	thread_create(void *philo);
void	init_thread(t_data_ph **philo);


#endif
