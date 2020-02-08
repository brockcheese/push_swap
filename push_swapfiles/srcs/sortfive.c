/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:33:28 by bpace             #+#    #+#             */
/*   Updated: 2019/09/26 01:44:55 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sortfivem(t_stack **stacka, t_stack **stackb, t_data *data, int *fd)
{
	getmaxmin(*stacka, data);
	numofmovesa(*stacka, data->max, data);
	while ((*stacka)->i != data->max)
	{
		if (data->au == 0)
		{
			r(stacka);
			write(fd[1], "ra\n", 3);
		}
		else
		{
			rr(stacka);
			write(fd[1], "rra\n", 4);
		}
		if (data->v == 1)
			printstack(*stacka, *stackb);
	}
	p(stackb, stacka);
	write(fd[1], "pb\n", 3);
	if (data->v == 1)
		printstack(*stacka, *stackb);
}

void	sortfivemin(t_stack **stacka, t_stack **stackb, t_data *data, int *fd)
{
	numofmovesa(*stacka, data->min, data);
	while ((*stacka)->i != data->min && data->size == 5)
	{
		if (data->au == 0)
		{
			r(stacka);
			write(fd[1], "ra\n", 3);
		}
		else
		{
			rr(stacka);
			write(fd[1], "rra\n", 4);
		}
		if (data->v == 1)
			printstack(*stacka, *stackb);
	}
	if (data->size == 5)
	{
		p(stackb, stacka);
		write(fd[1], "pb\n", 3);
		if (data->v == 1)
			printstack(*stacka, *stackb);
	}
}

void	sortfive(t_stack **stacka, t_stack **stackb, t_data *data, int *fd)
{
	sortfivem(stacka, stackb, data, fd);
	sortfivemin(stacka, stackb, data, fd);
	sortthree(stacka, stackb, data, fd);
	p(stacka, stackb);
	write(fd[1], "pa\n", 3);
	if (data->v == 1)
		printstack(*stacka, *stackb);
	if (data->size == 5)
	{
		p(stacka, stackb);
		write(fd[1], "pa\n", 3);
		if (data->v == 1)
			printstack(*stacka, *stackb);
	}
	r(stacka);
	write(fd[1], "ra\n", 3);
	if (data->v == 1)
		printstack(*stacka, *stackb);
}
