/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:06:36 by pramos            #+#    #+#             */
/*   Updated: 2023/12/12 20:58:44 by pramos           ###   ########.fr       */
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
# define fork_up "has taken a fork"
# define thinking "is thinking"
# define sleeping "is sleeping"
# define eating "is eating"
# define died "died"

//data of the philosopher
typedef struct s_data_ph
{
	int					id;
	int 				is_awake;
	int 				times_eat;
	u_int64_t			t_4_dead;
	pthread_mutex_t		*wait;
	pthread_mutex_t		*fork_right;
	pthread_mutex_t		*fork_left;
	struct	s_data		*data;

} t_data_ph;

//initial_data
typedef struct s_data
{
	int					dead;
	int 				n_of_ph;
	int 				n_ph_eat;
	u_int64_t			start_time;
	u_int64_t 			t_2_die;
	u_int64_t 			t_2_eat;
	u_int64_t 			t_2_sleep;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*print;
	pthread_t			*philosopher;
	t_data_ph			*ph;

} t_data;

//init_data
void		init(t_data *data, char **av, int ac);
void		init_data(t_data *data, char **argv, int ac);
void		init_philo(t_data *data);
void		new_philo(t_data *data, int i);

//utils
long 		ft_atoi(char *str);
u_int64_t	get_time(void);

//threads
void	*thread_create(void *ph);
void	init_thread(t_data *data);
void	forks_up(t_data_ph *philo);
void	forks_down(t_data_ph *philo);
void	print(t_data_ph *philo, char *message);

//philos_things
void	eat(t_data_ph *philo);
void	slep(t_data_ph *philo);
void	think(t_data_ph *philo);


#endif
