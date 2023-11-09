/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:08:04 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/11/09 17:14:39 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int cont = 0;
pthread_mutex_t lock;

void  *routine()
{
  int i;

  i = -1;
  while (++i < 1000000)
  {
    pthread_mutex_lock(&lock);
  	  cont++;
    pthread_mutex_unlock(&lock);
  }
  return (NULL);
}

int main()
{
  pthread_t tid1, tid2, tid3;

  pthread_mutex_init(&lock, NULL);
  pthread_create(&tid1, NULL, &routine, NULL);
  pthread_create(&tid2, NULL, &routine, NULL);
  pthread_create(&tid3, NULL, &routine, NULL);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  pthread_join(tid3, NULL);
  pthread_mutex_destroy(&lock);
  printf("cont: %d\n", cont);
}
