/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diningphilo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:40:21 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/10/30 19:04:27 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS	5

enum { THINING, HUNGRY, EATING };

pthread_mutex_t	forks[NUM_PHILOSOPHERS];
pthread_cond_t	cond[NUM_PHILOSOPHERS];
int				state[NUM_PHILOSOPHERS];

void	test_eat(int i)
{
	if (state[i] == HUNGRY && state[(i + 1) % NUM_PHILOSOPHERS] != EATING && state[(i + 4) % NUM_PHILOSOPHERS] != EATING)
	{
		state[i] = EATING;
		printf("Philosopher %d is eating\n", i);
		pthread_cond_signal(&cond[i]);
	}
}

void	pickup_forks(int i)
{
	pthread_mutex_lock(&forks[i]);
	state[i] = HUNGRY;
	printf("Philosopher %d is hungry\n", i);
	test_eat(i);
	while (state[i] != EATING)
		pthread_cond_wait(&cond[i], &forks[i]);
	pthread_mutex_unlock(&forks[i]);
}

void	putdown_forks(int i)
{
	pthread_mutex_lock(&forks[i]);
	state[i] = THINING;
	printf("Philosopher %d is thinking\n", i);
	test_eat((i + 1) % NUM_PHILOSOPHERS);
	test_eat((i + 4) % NUM_PHILOSOPHERS);
	pthread_mutex_unlock(&forks[i]);
}

void	*philosopher(void *arg)
{
	int	philosopher_id = *(int *)arg;

	while (1)
	{
		// Think for a while
		sleep(rand() % 3);

		// Pick up forks
		pickup_forks(philosopher_id);

		// Eat for a while
		sleep(rand() % 3);

		// Put down forks
		putdown_forks(philosopher_id);
	}
}

int	main()
{
	pthread_t	threads[NUM_PHILOSOPHERS];
	int			thread_args[NUM_PHILOSOPHERS];

	// Initialize mutexes and condition variables
	for (int i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		pthread_mutex_init(&forks[i], NULL);
		pthread_cond_init(&cond[i], NULL);
		state[i] = THINING;
	}

	for (int i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		thread_args[i] = i;
		if (pthread_create(&threads[i], NULL, philosopher, &thread_args[i]) != 0)
		{
			perror("Thread creatin failed");
			return (1);
		}
	}

	for (int i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		pthread_join(threads[i], NULL);
	}

	return (0);
}