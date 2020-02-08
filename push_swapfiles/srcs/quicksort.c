/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:26:35 by bpace             #+#    #+#             */
/*   Updated: 2019/09/26 02:25:09 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	threeshit(t_stack **stacka, t_stack **stackb, t_data *data, int *fd)
{
	sortthree(stacka, stackb, data, fd);
	data->max = (*stackb)->i;
	while (*stackb)
	{
		if ((*stacka)->prev->i != data->max &&
		(*stacka)->prev->i > (*stackb)->i)
		{
			rr(stacka);
			write(fd[1], "rra\n", 4);
			data->max = ((*stacka)->i > data->max) ? (*stacka)->i : data->max;
		}
		else
		{
			p(stacka, stackb);
			write(fd[1], "pa\n", 3);
		}
		if (data->v == 1)
			printstack(*stacka, *stackb);
	}
	while ((*stacka)->i > (*stacka)->prev->i)
	{
		rr(stacka);
		write(fd[1], "rra\n", 4);
	}
}

void	pushtwo(t_stack **stacka, t_stack **stackb, t_data *data, int *fd)
{
	p(stackb, stacka);
	write(fd[1], "pb\n", 3);
	if (data->v == 1)
		printstack(*stacka, *stackb);
	data->min = (*stackb)->i;
	p(stackb, stacka);
	write(fd[1], "pb\n", 3);
	if (data->v == 1)
		printstack(*stacka, *stackb);
	if (data->min > (*stackb)->i)
	{
		data->max = data->min;
		data->min = (*stackb)->i;
	}
	else
		data->max = (*stackb)->i;
}

void	quicksort(t_stack **stacka, t_stack **stackb, t_data *data, int *fd)
{
	pushtwo(stacka, stackb, data, fd);
	while ((*stacka)->prev->i != (*stacka)->next->next->i)
	{
		data->smallest = getsmallest(*stacka, *stackb, data);
		numofmoves(*stacka, *stackb, data->smallest, data);
		sortsmallest(stacka, stackb, data, fd);
	}
	numofmovesa(*stackb, data->max, data);
	while ((*stackb)->i != data->max)
	{
		if (data->au == 0)
		{
			r(stackb);
			write(fd[1], "rb\n", 3);
		}
		else
		{
			rr(stackb);
			write(fd[1], "rrb\n", 4);
		}
		if (data->v == 1)
			printstack(*stacka, *stackb);
	}
	threeshit(stacka, stackb, data, fd);
}
