/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larra <larra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:04:23 by larra             #+#    #+#             */
/*   Updated: 2023/07/20 18:20:42 by larra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	check_numeric(char **args);
int ft_is_numeric(char *str);
int	ft_atoi(const char *nptr);

int check_args(int argc, char **argv, struct s_param *param)
{
	if (argc != 5 && argc != 6)
		return (1);
	if (check_numeric(&argv[1]))
		return (2);
	param->philo_num =  ft_atoi(argv[1]);
	if (param->philo_num <= 0)
		return (3);
	param->t_to_die = ft_atoi(argv[2]);
	if (param->t_to_die <= 0)
		return (4);
	param->t_to_eat = ft_atoi(argv[3]);
	if (param->t_to_eat <= 0)
		return (5);
	param->t_to_slp = ft_atoi(argv[4]);
	if (param->t_to_slp <= 0)
		return (6);
	if (argc == 6)
	{
		param->eatend = ft_atoi(argv[5]);
		if (param->eatend < 0)
			return (7);
	}
	else
		param->eatend = -1;
	return (0);
}

int	check_numeric(char **args)
{
	int	n;

	n = 0;
	while (args[n])
	{
		if (ft_is_numeric(args[n]))
			return (1);
		n++;
	}
	return (0);
}

int	ft_is_numeric(char *str)
{
	int	n;
	n = 0;
	while (str[n])
	{
		if (!(str[n] >= '0' && str[n] <= '9'))
			return (1);
		n++;
	}
	return (0);
}

int	ft_atoi(const char *nptr)
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