/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larra <larra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:53:45 by larra             #+#    #+#             */
/*   Updated: 2023/07/18 16:43:10 by larra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	main(int argc, char **argv)
{
	struct s_all	all;
	int				err;
	
	err = 0;
	err = check_args(argc, argv, &all.param)
	if (err)	
		return (ft_error(1));
	err = 
}