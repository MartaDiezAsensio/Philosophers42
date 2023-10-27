/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:16:57 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/10/27 19:09:26 by mdiez-as         ###   ########.fr       */
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
    int             number; // Philosopher number
    pthread_mutex_t fork; // Fork for this philosopher
} Philosopher;


// Fnction to get the current timestamp in milliseconds
long long   current_time_ms()
{
    struct timeval now;
    gettimeofday(&now, NULL);
    return (long long)now.tv_sec * 1000 + now.tv_usec / 100;
}

void    long_message()