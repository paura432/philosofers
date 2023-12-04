/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:06:36 by pramos            #+#    #+#             */
/*   Updated: 2023/12/04 19:45:22 by pramos           ###   ########.fr       */
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
	pthread_mutex_t		wait;
	pthread_mutex_t		*fork_right;
	pthread_mutex_t		*fork_left;

	struct	s_data		*data;

} t_data_ph;

//initial_data
typedef struct s_data
{

	int 				n_of_ph;
	int 				n_ph_eat;
	u_int64_t 			t_2_die;
	u_int64_t 			t_2_eat;
	u_int64_t 			t_2_sleep;
	long int			start_time;
	t_data_ph			*ph;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*wait;
	pthread_t			*philosopher;

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
long int	get_time(void);

//threads
void	*thread_create(void *ph);
void	init_thread(t_data *data);


#endif
