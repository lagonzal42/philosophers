/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_check_parameters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:50:04 by lagonzal          #+#    #+#             */
/*   Updated: 2023/10/03 16:08:09 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static int	ft_atoi(const char *nptr);

int	check_parameters(int argc, char **argv, t_param *params)
{
	if (argc < 5 || argc > 6)
		return (ft_error_msg("number of parameters"), 1);
	params->philo_num = ft_atoi(argv[1]);
	if (params->philo_num < 1)
		return (ft_error_msg("number of philosophers"), 1);
	params->t_to_die = ft_atoi(argv[2]);
	if (params->t_to_die < 1)
		return (ft_error_msg("time to die"), 1);
	params->t_to_eat = ft_atoi(argv[3]);
	if (params->t_to_eat < 1)
		return (ft_error_msg("time to eat"), 1);
	params->t_to_slp = ft_atoi(argv[4]);
	if (params->t_to_slp < 1)
		return (ft_error_msg("time to sleep"), 1);
	if (argc == 6)
	{
		params->eatend = ft_atoi(argv[5]);
		if (params->eatend < 1)
			return (ft_error_msg("number of times a philosopher must eat"), 1);
	}
	else
		params->eatend = -1;
}

static int	ft_atoi(const char *nptr)
{
	int	num;
	int	n;
	int	sign;

	num = 0;
	sign = 1;
	n = 0;
	while ((nptr[n] >= 9 && nptr[n] <= 13) || nptr[n] == 32)
		n++;
	if (nptr[n] == '+' || nptr[n] == '-')
	{
		if (nptr[n] == '-')
		{
			sign = -1;
		}
		n++;
	}
	while (nptr[n] >= '0' && nptr[n] <= '9')
	{
		num = (num * 10) + (nptr[n] - '0');
		n++;
	}
	return (num * sign);
}
