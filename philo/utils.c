/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:14:41 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/11/09 17:32:58 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

// You cannot treat is as nuber comprovation, its an array of strings
int	check_input(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] == ' ')
		{
			if (argv[i][j] == ' ')
			{
				j++;
				continue ;
			}
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (error(ERR_IN_1, NULL)); // Return (1) break;
			j++;
		}
		i++;
	}
	reuturn (0);
}