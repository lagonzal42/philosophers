/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larra <larra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:36:59 by larra             #+#    #+#             */
/*   Updated: 2023/10/04 12:27:59 by larra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void    wait_time(int wait_time, unsigned int start);
void philo_routine(t_philo *philo);


void    philo_wait_loop(void *philosopher)
{
    t_philo *philo;

    philo = (t_philo *)philosopher;
    while (!*philo->start);
    philo_routine(philo);
}

void philo_routine(t_philo *philo)
{
    if (philo->pos % 2 == 2)
        usleep(100);
    while (1)
    {
        pthread_mutex_lock(philo->right->fork);
        print_msg(philo->print_lock, philo->pos, 1);
        pthread_mutex_lock(philo->fork);
        print_msg(philo->print_lock, philo->pos, 1);
        pthread_mutex_unlock(philo->print_lock);
        wait_time(philo->param->t_to_eat, philo->start_time);
        print_msg(philo->print_lock, philo->pos, 2);
        pthread_mutex_unlock(philo->fork);
        pthread_mutex_unlock(philo->right->fork);
        wait_time(philo->param->t_to_slp, *philo->start_time);
        print_msg(philo->print_lock, philo->pos, 3);
    }
}


void    wait_time(int wait_time, unsigned int start)
{
    
}