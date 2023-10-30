/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:16:57 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/10/30 17:40:17 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h> //gettimeofday()

// Define the state of each philosopher
enum { THINKING, HUNGRY, EATING, SLEEPING, DEAD};

#define NUM_PHILOSOPHERS    100 // Define the number of philosophers

typedef struct
{
    int             number; // Philosopher number
    pthread_mutex_t *forks; // Fork for this philosopher
} Philosopher;


// Function to get the current timestamp in milliseconds
long long   current_time_ms()
{
    struct timeval now;
    gettimeofday(&now, NULL);
    return (long long)now.tv_sec * 1000 + now.tv_usec / 100;
}

void    log_message(int philosopher_number, const char *message)
{
    // Log messagess with timestamps
    printf("%lld %d %s\n", current_time_ms, philosopher_number, message);
    //fflush(stdout); // Needed for memory allocstion purpooses?
}

// Functions to manage forks

void    pickup_forks(Philosopher *philosopher)
{
    int number = philosopher->number;

    pthread_mutex_lock(&philosopher->forks[number]);
    pthread_mutex_lock(&philosopher->forks[(number + 1) % NUM_PHILOSOPHERS]);
    log_message(philosopher->number, "has taken two forks");
}

void    release_forks(Philosopher *philosopher)
{
    int number = philosopher->number;

    pthread_mutex_unlock(&philosopher->forks[number]);
    pthread_mutex_unlock(&philosopher->forks[(number + 1) % NUM_PHILOSOPHERS]);
    log_message(philosopher->number, "has released two forks");
}

// Create a Philosopher Behaviuor Function
void    *philosopher_behavior(void *arg)
{

    return (NULL);
}

// Parse comand-line arguments
    // Allocate memory fr an array of philosophers
    // Create threads for philosphers and set their initial states
    // wait for threads to finish
    // Cleaan up resurces and free memory

int main(int argc, char **argv)
{
    int         num_philosophers;
    Philosopher *philosophers;
    int         i;

    // Memory allocation
    num_philosophers = atoi(argv[1]);
    philosophers = (Philosopher *)malloc(num_philosophers * sizeof(Philosopher));
    if (!philosophers)
        return (1);

    // Create threads for each philosopher. Passing the corresponding Philosopher structure as an argument.
    i = 0;
    while (i < num_philosophers)
    {
        philosophers[i].number = i + 1;
        pthread_mutex_init(&philosophers[i].forks, NULL);
        i++;
    }
    // Create philosopher threads and set their initial state.
    return (0);
}


// pthread_create() : Creates individual thread.
//  Each thread represents a philosopher and runs the philosopher function. 
// Philosphers function
