/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_watcher_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:37:03 by larra             #+#    #+#             */
/*   Updated: 2023/10/16 14:36:51 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int check_end(t_philo *table, t_param *parameters, unsigned int start_time,
				pthread_mutex_t *print_lock);

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
	watcher->start = 1;
	while (1)
	{
		if (check_end(table, parameters, start_time, watcher->print_lock))
			return;
	}
}

int check_end(t_philo *table, t_param *parameters, unsigned int start_time,
				pthread_mutex_t *print_lock)
{
	int i;
	int fed;

	i = 0;
	fed = 0;
	while (i < parameters->philo_num)
	{
		if ((unsigned)parameters->t_to_die < look_the_clock(start_time) - table->last_meal)
		{
			print_msg(print_lock, start_time, i + 1, 5);
			return (1);
		}
		if (table->meal == parameters->eatend)
			fed++;
		table = table->right;
		i++;
	}
	if (fed == parameters->philo_num)
	{
		pthread_mutex_lock(print_lock);
		return (1);
	}
	return (0);
}