/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_printer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:11:22 by larra             #+#    #+#             */
/*   Updated: 2023/10/24 13:31:00 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	print_msg(pthread_mutex_t *print_lock, unsigned int st, int pos, int op)
{
	pthread_mutex_lock(print_lock);
	if (op == 1)
		printf("%dms philo%d has taken a fork\n", look_the_clock(st),
				 pos);
	if (op == 2)
		printf("%dms philo%d has started eating\n", look_the_clock(st),
				 pos);
	if (op == 3)
		printf("%dms philo%d is sleeping\n", look_the_clock(st),
				pos);
	if (op == 4)
		printf("%dms philo%d is thinking\n", look_the_clock(st),
				pos);
	if (op == 5)
		printf("%dms philo%d is dead\n",  look_the_clock(st), pos);
	if (op < 5)
		pthread_mutex_unlock(print_lock);
	
}