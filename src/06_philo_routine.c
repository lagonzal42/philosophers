/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:36:59 by larra             #+#    #+#             */
/*   Updated: 2023/11/16 20:38:18 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	wait_time(unsigned int wait_time);
void	philo_routine(t_philo *philo);

/*
This function is where the philo threads will wait until the start variable is
set to 1 by the watcher thread. Then it will call the philo_routine function.
This way we can make sure that all the threads start at the same time.
ARGS:
	- philosopher:	the pointer to the philosopher struct.
RETURN VALUE:
	void.
*/
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

/*
This function is the routine of the philosophers. It will lock the left and
right forks, print the message that the philosopher is eating, unlock the forks,
print the message that the philosopher is sleeping and then it will loop again.
It applies a usleep of 15 milliseconds to the even philosophers so they don't
start looking for the forks at the same time to prevent of a deadlock.
Uses the param lock in order to prevent data races when updating the last_meal
and meal variables.
ARGS:
	- philo:	the pointer to the philosopher struct.
*/

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

/*
This function will wait until the time passed as parameter has passed. It will
wait atleast 500 microseconds each loop to prevent the program from using 
too much CPU.
ARGS:
	- wait_time:	the time in milliseconds to wait.
*/

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