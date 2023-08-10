/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larra <larra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:53:45 by larra             #+#    #+#             */
/*   Updated: 2023/08/10 20:50:14 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	main(int argc, char **argv)
{
	struct s_all	all;
	//struct s_param	param;
	//int				err;
	
	//err = 0;
	//all.param = param;
	if(check_args(argc, argv, &all.param))	
		return (ft_error(1));
	if (create_philos(&all))
		return (ft_error(2));
	thread_creation(&all);
	
}
