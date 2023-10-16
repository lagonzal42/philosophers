/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_free_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:09:13 by lagonzal          #+#    #+#             */
/*   Updated: 2023/10/05 15:37:59 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

/*
This function frees the philosophers that are seated in the table and frees
their mutexes.
ARGS:
	- table:	the pointer to the circular double linked list.
	- n:		the amount of philosophers that are already seated.
RETURN VALUE:
	void.
*/

void	free_table(t_philo *table, int n)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	tmp = table->right;
	while (i < n)
	{
		pthread_mutex_destroy(table->fork);
		free(table->fork);
		free(table);
		table = tmp;
		tmp = tmp->right;
		i++;
	}
}

/*
This function frees all the memory that has been allocated for all the threads.
ARGS:
	- watcher:	a pointer to the watcher struct.
RETURN VALUE:
	void.
*/
void	free_watcher(t_watcher *watcher)
{
	free(watcher->threads);
	free_table(watcher->table, watcher->param->philo_num);
	pthread_mutex_destroy(watcher->print_lock);
	free(watcher->print_lock);
}