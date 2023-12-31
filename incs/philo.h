/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:07:21 by larra             #+#    #+#             */
/*   Updated: 2023/11/16 20:52:02 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//INCLUDES

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

//COLOR MACROS

#define WT "\033[0;37m"
#define GR "\033[0;32m"
#define BL "\033[0;34m"
#define RD "\033[0;31m"

//STRUCTURES

/*
Param structure. This param structure saves the parameter data that is given
when executing the binary. 
	- philo_num:	number of philosophers to seat on the table.
	- t_to_die:		time a philo can wait between 2 meals before dying.
	- t_to_slp:		time a philo will spleep after eating.
	- t_to_eat:		time a philo will take to eat. 
	- eatend:		times all the philosophers should eat before stopping. this
					argument is optional
*/

typedef struct s_param
{
	int	philo_num;
	int	t_to_die;
	int	t_to_slp;
	int	t_to_eat;
	int	eatend;
}	t_param;

/*
Philo structure. This philo structure represents each of the philosophers
that will take part in the problem. This philosophers will be nodes in a 
circular double linked list (table from s_all).
	- left:			a pointer to the philosopher that will be on his left in
					the hypothetical table. 
	- right: 		a pointer to the philosopher that will be on his right in
					the hypothetical table.
	- last_meal:	the time that this philo last ate in ms.
	- start:		a pointer to the start variable in the watcher struct. This
					variable will be used to make sure that all the philos start
					at the same time.
	- start_time:	a pointer to the start_time variable in the watcher struct.
					This variable will be used to make sure that all the philos
					have the same start time of the program.
	- meal: 		the times this philo has already eaten.
	- pos:			the position of the philo on the table [1 - n].
	- fork:			the fork the philosopher carries to the table.
	- param:		a pointer to the parameters in order to check them if
					necesary.
	-print_lock:	a pointer to a mutex that will prevent the philos and the
					watcher from printing at the same time.
	- param_lock:	a pointer to a mutex that will prevent data races when
					updating the last_meal and meal variables or checking them
					in the watcher routine.
*/

typedef struct s_philo
{
	struct s_philo		*left;
	struct s_philo		*right;
	unsigned int		last_meal;
	char				*start;
	unsigned int		*start_time;
	int					meal;
	int					pos;
	pthread_mutex_t		*fork;
	t_param				*param;
	pthread_mutex_t		*print_lock;
	pthread_mutex_t		*param_lock;

}	t_philo;

/*
Watcher structure. This watcher structure will be the one that will be passed
to the watcher thread. It has access to the philo structures and to the
parameters.
	- param_lock:	a pointer to a mutex that will prevent data races when
					updating the last_meal and meal variables or checking them
					in the watcher routine.
	- param:		a pointer to the paramater structure.
	- table:		a pointer to the table where the philos are seated.
	- threads:		a pointer to the threads that will be launched as
					philosophers.
	- start_time:	the time in milliseconds when the program started.
	- start:		it will be used as a boolean to start the program.
	- print_lock:	a pointer to a mutex that will prevent the philos and the
					watcher from printing at the same time.
*/

typedef struct s_watcher
{
	pthread_mutex_t	*param_lock;
	t_param			*param;
	t_philo			*table;
	pthread_t		*threads;
	unsigned int	start_time;
	char			start;
	pthread_mutex_t	*print_lock;
}	t_watcher;

//PROTOTYPES

/*===============================01_CHECK_PARAMETERS=========================*/

int				check_parameters(int argc, char **argv, t_param *params);

/*================================02_ERROR_MSG===============================*/

void			param_error_msg(char *error_msg);

/*================================03_CREATE_PHILOS===========================*/

int				create_philos(t_watcher *watcher);

/*================================04_FREE_ELEMENTS===========================*/

void			free_table(t_philo *table, int n);

/*================================05_THREAD_CREATE===========================*/

int 			thread_create(t_watcher *watcher);
unsigned int    look_the_clock(unsigned int start);

/*================================06_PHILO_ROUTINE===========================*/

void   			philo_wait_loop(void *philosopher);
void    		wait_time(unsigned int wait_time);

/*==============================07_WATCHER_ROUTINE===========================*/

void    		watcher_routine(void *watcher_info);

/*==============================07_WATCHER_ROUTINE===========================*/

void			print_msg(pthread_mutex_t *print_lock, unsigned int st,
							int pos, int op);

#endif
