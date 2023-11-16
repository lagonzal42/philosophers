/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:20:49 by lagonzal          #+#    #+#             */
/*   Updated: 2023/11/16 20:49:39 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static t_philo	*philo_init(t_watcher *watcher, int n);
static void		take_a_seat(t_philo **table, t_philo *new, int n);
int				watcher_create(t_watcher *watcher);


/*
This function uses the data in param that is nested in watcher to create the
philo structures. It allocates memory for the mutexes, the threads and then
creates a circular double linked list with the philosophers (as a round table).
ARGS:
	- watcher:	a pointer to the watcher struct. It is sent by the main to
				complete the table inside of it.
RETURN VALUES:
	1 in case of error, 0 in case of success.
*/

int	create_philos(t_watcher *watcher)
{
	int		n;
	t_philo	*tmp;

	n = 0;
	if (watcher_create(watcher))
		return (1);
	while (n < watcher->param->philo_num)
	{
		tmp = philo_init(watcher, n);
		if (!tmp)
			return (pthread_mutex_destroy(watcher->print_lock),
					free(watcher->print_lock), free_table(watcher->table, n),
					free(watcher->threads), 1);
		take_a_seat(&watcher->table, tmp, n);
		n++;
	}
	return (0);
}

int	watcher_create(t_watcher *watcher)
{
	watcher->threads = malloc(watcher->param->philo_num * (sizeof(pthread_t)));
	if (!watcher->threads)
		return (1);
	watcher->start = 0;
	watcher->print_lock = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(watcher->print_lock, NULL) != 0)
		return (free(watcher->threads), 1);
	watcher->param_lock = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(watcher->param_lock, NULL) != 0)
		return (free(watcher->threads)
				,pthread_mutex_destroy(watcher->print_lock), free(watcher->print_lock)
				, 1);
	watcher->table = NULL;
	return (0);
}

/*
This function is used to initialize the philosopher structure. It assignes
NULL values to the pointers that, allocates and initializes the fork, 
nests the param structure into the philo and assignes the common mutex.
ARGS:
	- watcher:	The watcher structure needed to get the params and the
				print_lock.
	- n:		The variable that indicates the position of the philosopher
				in the table.	
RETURN VALUES:
	the philosopher in case of success, NULL in case of error
*/

static t_philo	*philo_init(t_watcher *watcher, int n)
{
	t_philo	*tmp;

	tmp = malloc(sizeof(t_philo));
	if (!tmp)
		return (NULL);
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->last_meal = 0;
	tmp->start = &watcher->start;
	tmp->start_time = &watcher->start_time;
	tmp->meal = 0;
	tmp->pos = n + 1;
	tmp->fork = malloc(sizeof(pthread_mutex_t));
	if (!tmp->fork)
		return (free(tmp->fork), free(tmp), NULL);
	if  (pthread_mutex_init(tmp->fork, NULL) != 0)
		return (free(tmp), NULL);
	tmp->param = watcher->param;
	tmp->print_lock = watcher->print_lock;
	tmp->param_lock = watcher->param_lock;
	return (tmp);
}

/*
This function makes the pointer asignations to create the circular double
linked list. (The round table).
ARGS:
	- table:	the circular double linked list.
	- n:		the relative position in the table.
RETURN VALUES:
	void.
*/

void	take_a_seat(t_philo **table, t_philo *new, int n)
{
	t_philo *last_seat;
	int	m;

	m = 1;
	if (n == 0)
		*table = new;
	else
	{
		last_seat = *table;
		while (last_seat->right)
			last_seat = last_seat->right;
		last_seat->right = new;
		new->left = last_seat;
	}
	if (n == (*table)->param->philo_num - 1)
	{
		new->right = *table;
		(*table)->left = new;
	}
}
