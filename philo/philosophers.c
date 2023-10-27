/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:10:43 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/10/27 23:14:43 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h> //gettimeofday()

// Define the state of each philosopher
enum { THINKING, HUNGRY, EATING, SLEEPING, DEAD}; // Change HUNGRY for THINKING

typedef struct
{
	int				number; // Philosopher number
	pthread_mutex_t	fork; // Fork for this philosopher
} Philosopher;


// Function to get the current timestamp in milliseconds
long long	current_time_ms()
{
	struct timeval now;
	gettimeofday(&now, NULL);
	return (long long)now.tv_sec * 1000 + now.tv_usec / 100;
}

void	long_message(int philosopher_number, const char *message)
{
	// Log messagess with timestamps
	printf("%lld %d %s\n", current_time_ms, philosopher_number, message);
	fflush(stdout); // Needed for memory allocstion purpooses?
}

// Create a Philosopher Behaviuor Function
void	*philosopher_behavior(void *arg)
{
	Philosopher *philosopher = (Philosopher *)arg;
	// Implement philosopher's behaviour
	return (NULL);
}

int	main(int argc, char **argv)
{
	// Parse comand-line arguments
	// Allocate memory fr an array of philosophers
	// Creaate threads for philosphers and set their initia; states
	// wait for threads to finish
	// Cleaan up resurces and free memory
	return (0);
}