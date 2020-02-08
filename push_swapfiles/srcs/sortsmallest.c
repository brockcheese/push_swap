/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortsmallest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:23:22 by bpace             #+#    #+#             */
/*   Updated: 2019/09/26 02:29:01 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotatestacks(t_stack **stacka, t_stack **stackb, t_data *data, int *fd)
{
	if (data->au == 0)
	{
		r(stacka);
		r(stackb);
		write(fd[1], "rr\n", 3);
	}
	else
	{
		rr(stacka);
		rr(stackb);
		write(fd[1], "rrr\n", 4);
	}
	if (data->v == 1)
		printstack(*stacka, *stackb);
}

void	rotatestack(t_stack **stack, int u, char c, int *fd)
{
	if (u == 0)
	{
		r(stack);
		write(fd[1], "r", 1);
	}
	else
	{
		rr(stack);
		write(fd[1], "rr", 2);
	}
	write(fd[1], &c, 1);
	write(fd[1], "\n", 1);
}

void	sortsmallestm(t_stack **stacka, t_stack **stackb, t_data *data, int *fd)
{
	if (data->au == data->bu)
	{
		while ((*stacka)->i != data->smallest && (*stackb)->i != data->max)
			rotatestacks(stacka, stackb, data, fd);
	}
	while ((*stacka)->i != data->smallest)
	{
		rotatestack(stacka, data->au, 'a', fd);
		if (data->v == 1)
			printstack(*stacka, *stackb);
	}
	while ((*stackb)->i != data->max)
	{
		rotatestack(stackb, data->bu, 'b', fd);
		if (data->v == 1)
			printstack(*stacka, *stackb);
	}
	if (data->smallest > data->max)
		data->max = data->smallest;
	else
		data->min = data->smallest;
}

void	sortsmalleste(t_stack **stacka, t_stack **stackb, t_data *data, int *fd)
{
	if (data->au == data->bu)
	{
		while ((*stacka)->i != data->smallest &&
				((*stackb)->i > data->smallest ||
				(*stackb)->prev->i < data->smallest))
			rotatestacks(stacka, stackb, data, fd);
	}
	while ((*stacka)->i != data->smallest)
	{
		rotatestack(stacka, data->au, 'a', fd);
		if (data->v == 1)
			printstack(*stacka, *stackb);
	}
	while ((*stackb)->i > data->smallest ||
			(*stackb)->prev->i < data->smallest)
	{
		rotatestack(stackb, data->bu, 'b', fd);
		if (data->v == 1)
			printstack(*stacka, *stackb);
	}
}

void	sortsmallest(t_stack **stacka, t_stack **stackb, t_data *data, int *fd)
{
	if (data->smallest > data->max || data->smallest < data->min)
		sortsmallestm(stacka, stackb, data, fd);
	else
		sortsmalleste(stacka, stackb, data, fd);
	p(stackb, stacka);
	write(fd[1], "pb\n", 3);
	if (data->v == 1)
		printstack(*stacka, *stackb);
}
