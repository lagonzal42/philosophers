/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:36:59 by larra             #+#    #+#             */
/*   Updated: 2023/10/24 14:00:57 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	wait_time(unsigned int wait_time);
void	philo_routine(t_philo *philo);


void	philo_wait_loop(void *philosopher)
{
	t_philo *philo;

	philo = (t_philo *)philosopher;
	while (1)
	{
		pthread_mutex_lock(philo->print_lock);
		if (*philo->start)
		{
			pthread_mutex_unlock(philo->print_lock);
			break;
		}
		pthread_mutex_unlock(philo->print_lock);
	}
	philo_routine(philo);
}

void	philo_routine(t_philo *philo)
{
	if (philo->pos % 2 == 0)
		usleep(15000);
	while (1)
	{
		pthread_mutex_lock(philo->fork);
		print_msg(philo->print_lock, *philo->start_time, philo->pos, 1);
		pthread_mutex_lock(philo->right->fork);
		print_msg(philo->print_lock, *philo->start_time, philo->pos, 1);
		print_msg(philo->print_lock, *philo->start_time, philo->pos, 2);
		pthread_mutex_lock(philo->param_lock);
		philo->last_meal = look_the_clock(*philo->start_time);
		philo->meal++;
		pthread_mutex_unlock(philo->param_lock);
		wait_time(philo->param->t_to_eat);
		pthread_mutex_unlock(philo->fork);
		pthread_mutex_unlock(philo->right->fork);
		print_msg(philo->print_lock, *philo->start_time, philo->pos, 3);
		wait_time(philo->param->t_to_slp);
		print_msg(philo->print_lock, *philo->start_time, philo->pos, 4);
	}
}


void    wait_time(unsigned int wait_time)
{
	unsigned int	start_time;
	unsigned int	waited_time;

	start_time = look_the_clock(0);
	waited_time = 0;
	while (waited_time < wait_time)
	{
		usleep(500);
		waited_time = look_the_clock(start_time);
	}
}