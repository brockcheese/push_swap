/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortthree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:17:18 by bpace             #+#    #+#             */
/*   Updated: 2019/09/25 21:32:22 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	getmaxmin(t_stack *stacka, t_data *data)
{
	t_stack		*temp;

	temp = stacka;
	data->max = temp->i;
	data->min = temp->i;
	temp->prev->next = NULL;
	while (temp)
	{
		if (temp->i > data->max)
			data->max = temp->i;
		if (temp->i < data->min)
			data->min = temp->i;
		temp = temp->next;
	}
	stacka->prev->next = stacka;
}

void	sortthreemin(t_stack **stacka, t_stack **stackb, int v, int *fd)
{
	r(stacka);
	write(fd[1], "ra\n", 3);
	if (v == 1)
		printstack(*stacka, *stackb);
	s(stacka);
	write(fd[1], "sa\n", 3);
	if (v == 1)
		printstack(*stacka, *stackb);
	rr(stacka);
	write(fd[1], "rra\n", 4);
	if (v == 1)
		printstack(*stacka, *stackb);
}

void	sortthreemax(t_stack **stacka, t_stack **stackb, t_data *data, int *fd)
{
	if ((*stacka)->prev->i != data->max)
	{
		if ((*stacka)->i == data->max)
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
	if ((*stacka)->i != data->min)
	{
		s(stacka);
		write(fd[1], "sa\n", 3);
		if (data->v == 1)
			printstack(*stacka, *stackb);
	}
}

void	sortthree(t_stack **stacka, t_stack **stackb, t_data *data, int *fd)
{
	if (!checkbegin(*stacka, 3))
	{
		if (data->size == 2)
		{
			s(stacka);
			write(fd[1], "sa\n", 3);
			if (data->v == 1)
				printstack(*stacka, NULL);
		}
		else
		{
			getmaxmin(*stacka, data);
			if ((*stacka)->i == data->min)
				sortthreemin(stacka, stackb, data->v, fd);
			else
				sortthreemax(stacka, stackb, data, fd);
		}
	}
}
