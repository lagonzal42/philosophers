/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_thread_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:58:37 by larra             #+#    #+#             */
/*   Updated: 2023/11/16 20:33:47 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

/*
This functions creates the n threads that shall be passed as first parameter
to the executable. This threads will do the routine of the philosophers (eat,
sleep and think). Then it creates a watcher thread that will end when a
philosopher dies or when all the philos are fed and will end the program when
that happens.
ARGS:
    - watcher: a pointer to the watcher structure, already initialized.
RETURN:
    - 0 if everything went well, 1 if there was an error.
*/

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

/*
This function checks the time in milliseconds compared to the start time.
ARGS:
    - start: the time to be compared in miliseconds.
RETURN:
    - the time in milliseconds since the start time.
*/

unsigned int    look_the_clock(unsigned int start)
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    return (((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) - start);
}