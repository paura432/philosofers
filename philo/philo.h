/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:06:36 by pramos            #+#    #+#             */
/*   Updated: 2024/01/29 20:51:40 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

//	philo_msg
# define FORK_UP "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"

//data of the philosopher
typedef struct s_data_ph
{
	int					id;
	int					is_awake;
	int					eat;
	u_int64_t			t_4_dead;
	pthread_mutex_t		*fork_right;
	pthread_mutex_t		*fork_left;
	struct s_data		*data;

}	t_data_ph;

//initial_data
typedef struct s_data
{
	int					dead;
	int					id_ph;
	int					n_of_ph;
	int					n_ph_eat;
	int					times_eat;
	u_int64_t			start_time;
	u_int64_t			t_2_die;
	u_int64_t			t_2_eat;
	u_int64_t			t_2_sleep;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*wait;
	pthread_mutex_t		*print;
	pthread_t			*philosopher;
	t_data_ph			*ph;

}	t_data;

//init_data
void		init(t_data *data, char **av, int ac);
void		init_data(t_data *data, char **argv, int ac);
void		init_philo(t_data *data);
void		new_philo(t_data *data, int i);
int			check_errors( char **av, int ac);

//utils
long		ft_atoi(char *str);
u_int64_t	get_time(void);
int			ft_usleep(t_data_ph *philo, u_int64_t time);
void		finish_thread(t_data *data);

//threads
void		*thread_create(void *ph);
void		init_thread(t_data *data);
void		forks_up(t_data_ph *philo);
void		forks_down(t_data_ph *philo);
int			philo_continue(t_data_ph *philo);

//philo.c
int			print(t_data_ph *philo, char *message);

//philos_things
void		eat(t_data_ph *philo);
void		slep(t_data_ph *philo);

#endif
