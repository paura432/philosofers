/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:06:36 by pramos            #+#    #+#             */
/*   Updated: 2023/12/05 20:48:19 by pramos           ###   ########.fr       */
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
# define FORK_UP "has taken a fork"
# define think "is thinking"
# define sleep "is sleeping"
# define eat "is eating"
# define died "died"

//data of the philosopher
typedef struct s_data_ph
{
	int					id;
	int					is_dead;
	int 				is_awake;
	u_int64_t			t_4_dead;
	pthread_mutex_t		*wait;
	pthread_mutex_t		*fork_right;
	pthread_mutex_t		*fork_left;
	struct	s_data		*data;

} t_data_ph;

//initial_data
typedef struct s_data
{
	int 				n_of_ph;
	int 				n_ph_eat;
	u_int64_t			start_time;
	u_int64_t 			t_2_die;
	u_int64_t 			t_2_eat;
	u_int64_t 			t_2_sleep;
	pthread_mutex_t		*forks;
	pthread_t			*philosopher;
	t_data_ph			*ph;

} t_data;

//list
t_data_ph	*lstlast(t_data_ph *lst);
void		lstadd_back(t_data_ph **lst, t_data_ph *new);

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
void	take_forks(t_data_ph *ph);
void	forks_up(t_data_ph *philo);
void	forks_down(t_data_ph *philo);


#endif
