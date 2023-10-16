/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:53:45 by larra             #+#    #+#             */
/*   Updated: 2023/10/05 18:31:45 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	main(int argc, char **argv)
{
	struct s_param		params;
	struct s_watcher	watcher;
	

	if (check_parameters(argc, argv, &params))
		return (1);
	watcher.param = &params;
	if (create_philos(&watcher))
		return (1);
	thread_create(&watcher);
}
