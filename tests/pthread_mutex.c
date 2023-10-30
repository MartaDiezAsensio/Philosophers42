/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:17:06 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/10/30 18:39:13 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int	shared_data = 0;

pthread_mutex_t	mutex;

void	*thread1(void *arg)
{
	pthread_mutex_lock(&mutex);
	printf("Thread 1 acquired the mutex\n");

	shared_data += 5;
	pthread_mutex_unlock(&mutex);
	printf("Thread 1 released the mutex\n");
	return (NULL);
}

void	*thread2(void *arg)
{
	pthread_mutex_lock(&mutex);
	printf("Thread 2 acquired the mutex\n");
	shared_data -= 3;
	pthread_mutex_unlock(&mutex);
	printf("Thread 2 released the mutex\n");

	return (NULL);
}

int	main()
{
	pthread_t	t1, t2;

	// Initialize the mutex
	if (pthread_mutex_init(&mutex, NULL) != 0)
	{
		perror("Mutex initialaion failed");
		return (1);
	}

	// Create two threads
	if (pthread_create(&t1, NULL, thread1, NULL) != 0 ||
		pthread_create(&t2, NULL, thread2, NULL) != 0)
	{
		perror("Thread creatin failed");
		return (2);
	}

	// wait for both threads to finish
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	// Destroy the mutex
	pthread_mutex_destroy(&mutex);

	printf("Shared data: %d\n", shared_data);

	return (0);
}