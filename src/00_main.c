/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larra <larra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:53:45 by larra             #+#    #+#             */
/*   Updated: 2023/07/06 13:17:51 by larra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	main(int argc, char **argv)
{
	struct  param;
	int		err;
	
	err = 0;
	err = check_args(argc, argv, &param)
	if (err)	
		return (ft_error(1));
	
}