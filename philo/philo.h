/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:08:58 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/10/30 19:17:19 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

struct	s_data;

typedef struct s_philo
{
	struct	s_data	*data;
	pthread_t		t1;
	int				id;
	int				eaat_cont;
	int				status;
	int				eating;
	uint64_t		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}t_philo;

typedef struct s_data
{
	pthread_t		*tid;
	int				philo_num;
	int				meals_nb;
	int				dead;
	int				finished;
	t_philo			*philos;
	u_int64_t		death_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}t_data;

//https://github.com/TommyJD93/Philosophers