/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_thread_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larra <larra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:58:37 by larra             #+#    #+#             */
/*   Updated: 2023/10/04 12:46:59 by larra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int thread_create(t_watcher *watcher)
{
    int         n;
    pthread_t   watcher_thread;

    n = -1;
    while (++n < watcher->param->philo_num)
    {
        if (pthread_create(&watcher->threads[n], NULL, (void *)&philo_wait_loop,
                        (void *)watcher->table) != 0)
            return (1);
        watcher->table = watcher->table->right;
    }
    watcher->start_time = look_the_clock(watcher->start_time);
    if (pthread_create(&watcher_thread, NULL, (void *)&watcher_routine, (void *)watcher) != 0)
        return (1);
    pthread_join(watcher_thread, NULL);
    exit (0);
}

unsigned int    look_the_clock(unsigned int start)
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000) - start);
}