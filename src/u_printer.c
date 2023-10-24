/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_printer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:11:22 by larra             #+#    #+#             */
/*   Updated: 2023/10/24 10:20:04 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	print_msg(pthread_mutex_t *print_lock, unsigned int st, int pos, int op)
{
	pthread_mutex_lock(print_lock);
	if (op == 1)
		printf("%s%dms %sphilo%d %shas taken a fork\n", GR, look_the_clock(st),
				BL, pos, WT);
	if (op == 2)
		printf("%s%dms %sphilo%d %shas started eating\n", GR, look_the_clock(st),
				BL, pos, WT);
	if (op == 3)
		printf("%s%dms %sphilo%d %sis sleeping\n", GR, look_the_clock(st), BL,
				pos, WT);
	if (op == 4)
		printf("%s%dms %sphilo%d %sis thinking\n", GR, look_the_clock(st), BL,
				pos, WT);
	if (op == 5)
		printf("%s%dms %sphilo%d %sis dead\n%s", GR, look_the_clock(st), BL,
				pos, RD, WT);
	if (op < 5)
		pthread_mutex_unlock(print_lock);
	
}