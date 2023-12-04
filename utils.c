/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:53:59 by pramos            #+#    #+#             */
/*   Updated: 2023/12/04 17:53:13 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi(char *str)
{
	int	i;
	long	a;
	int	signo;

	a = 0;
	signo = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
	{
		signo = -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	while (str[i] > 47 && str[i] < 58)
		a = a * 10 + (str[i++] - '0');
	return (a * signo);
}

long int	get_time(void)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) == -1)
	{
		perror("Error in gettimeofday");
		return 0;
	}
	return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

