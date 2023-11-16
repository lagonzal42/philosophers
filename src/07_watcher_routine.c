/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_watcher_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:37:03 by larra             #+#    #+#             */
/*   Updated: 2023/11/16 20:44:17 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int check_end(t_philo *table, t_param *parameters, unsigned int start_time,
				pthread_mutex_t *print_lock);

/*
This fucntion will set the start value for the philos to start looping and then
it will start checking if the philosophers are dead or if they have eaten enough
times to stop the program.
ARGS:
	- watcher_info:	the pointer to the watcher struct.
*/

void    watcher_routine(void *watcher_info)
{
	t_watcher		*watcher;
	t_philo			*table;
	t_param			*parameters;
	unsigned int	start_time;

	watcher = (t_watcher *)watcher_info;
	table = watcher->table;
	parameters = watcher->param;
	start_time = watcher->start_time;
	pthread_mutex_lock(watcher->print_lock);
	watcher->start = 1;
	pthread_mutex_unlock(watcher->print_lock);
	while (1)
	{
		if (check_end(table, parameters, start_time, watcher->print_lock))
			return;
	}
}

/*
This function checks if the philosophers are dead or if they have eaten enough
times to stop the program. It will check the time of the last meal of each
philosopher of the table and compare it to the time to die. If the time to die
is less than the time of the last meal, it will print the message that the
philosopher is dead. If all the philosophers have eaten enough
times, it will lock the printer in order to prevent the philos from printing
more messages. It will wait 10 miliseconds between each check to prevent
unnecesary cpu usage and make the philos run their routine more easily.
ARGS:
	- table:		the pointer to the first philosopher of the table.
	- parameters:	the pointer to the parameters struct.
	- start_time:	the time in milliseconds when the program started.
	- print_lock:	the pointer to the printer lock.
RETURN VALUE:
	- 1 if the philosophers are dead or if they have eaten enough times to stop
	the loop, 0 otherwise.
*/

int check_end(t_philo *table, t_param *parameters, unsigned int start_time,
				pthread_mutex_t *print_lock)
{
	int i;
	int fed;

	i = 0;
	fed = 0;
	while (i < parameters->philo_num)
	{
		pthread_mutex_lock(table->param_lock);
		if ((unsigned)parameters->t_to_die < look_the_clock(start_time) - table->last_meal)
		{
			pthread_mutex_unlock(table->param_lock);
			print_msg(print_lock, start_time, i + 1, 5);
			return (1);
		}
		if (table->meal >= parameters->eatend)
			fed++;
		pthread_mutex_unlock(table->param_lock);
		usleep(100);
		table = table->right;
		i++;
	}
	if (fed == parameters->philo_num)
		return (pthread_mutex_lock(print_lock), 1);
	return (0);
}
