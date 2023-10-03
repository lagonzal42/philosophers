/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:20:49 by lagonzal          #+#    #+#             */
/*   Updated: 2023/10/03 19:09:56 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

t_philo	*philo_init(t_watcher *watcher, int n);
void	take_a_seat(t_philo *table, t_philo *new, int n);


int	create_philos(t_watcher *watcher)
{
	int		n;
	t_philo	*tmp;

	n = 0;
	watcher->threads = malloc(watcher->param->philo_num * (sizeof(pthread_t)));
	if (!watcher->threads)
		return (1);
	watcher->start = 0;
	watcher->dead = 0;
	watcher->print_lock = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(watcher->print_lock, NULL) == 0)
		return (free(watcher->threads), 1);
	watcher->table = NULL;
	while (n < watcher->param->philo_num)
	{
		tmp = philo_init(watcher, n);
		if (!tmp)
			return (pthread_mutex_destroy(watcher->print_lock),
					free(watcher->print_lock), free_table(watcher->table, n),
					free(watcher->threads), 1);
		take_a_seat(watcher->table, tmp, n);
		n++;
	}
	return (0);
}

static t_philo	*philo_init(t_watcher *watcher, int n)
{
	t_philo	*tmp;

	tmp = malloc(sizeof(t_philo));
	if (!tmp)
		return (NULL);
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->last_meal = 0;
	tmp->meal = 0;
	tmp->pos = n;
	tmp->fork = malloc(sizeof(pthread_mutex_t));
	if (!tmp->fork)
		return (free(tmp->fork), free(tmp), NULL);
	if  (pthread_mutex_init(tmp->fork, NULL) != 0)
		return (free(tmp), NULL);
	tmp->param = watcher->param;
	tmp->print_lock = &watcher->print_lock;
}

void	take_a_seat(t_philo *table, t_philo *new, int n)
{
	t_philo *last_seat;

	if (n == 0)
		table = new;
	else
	{
		last_seat = table;
		while (last_seat && last_seat->right)
			last_seat = last_seat->right;
		last_seat->right = new;
		new->left = last_seat;
	}
	if (n == table->param->philo_num - 1)
	{
		new->right = table;
		table->left = new;
	}
}
