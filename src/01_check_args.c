/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larra <larra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:04:23 by larra             #+#    #+#             */
/*   Updated: 2023/07/19 20:57:19 by larra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"
#include "../incs/libft.h"

int	check_numeric(char **args);
int ft_is_numeric(char *str);

int check_args(int argc, char **argv, t_param *param)
{
	if (argc != 5 && argc != 6)
		return (1);
	if (check_numeric(&arv[1]))
		return (2);
	param->philo_num =  ft_atoi(argv[1]);
	if (param->philo_num <= 0)
		return (3);
	param->t_to_die = ft_atoi(argv[2]);
	if (param->t_to_die <= 0)
		return (4);
	param->t_to_eat = ft_atoi(argv[3])
	if (param->t_to_eat <= 0)
		return (5);
	param->t_to_slp; = ft_atoi(argv[4])
	if (param->t_to_spl <= 0)
		return (6);
	if (argc == 6)
	{
		param->eat_end = ft_atoi(argv[5]);
		if (param->eat_end < 0)
			return (7);
	}
	else
		param->eat_end = -1;
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
}