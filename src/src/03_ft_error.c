/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_ft_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larra <larra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:45:44 by larra             #+#    #+#             */
/*   Updated: 2023/07/20 14:06:35 by larra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	ft_error(int ecode)
{
	write(2, "Error\n", 6);
	if (ecode == 1)
		printf("Error in the parameters\n");
	if (ecode == 2)
		printf("Error while alocating memory\n");
	return (1);
}