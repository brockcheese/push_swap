/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getsmallest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 23:28:30 by bpace             #+#    #+#             */
/*   Updated: 2019/09/26 01:59:12 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	normisbitch(int *tempm, int *smallest, t_stack **temp, t_data *data)
{
	if (*tempm == *smallest)
	{
		if ((*temp)->i < data->min)
			data->smallestnbr = (*temp)->i;
		else if ((*temp)->i > data->max)
			data->smallestnbr = (*temp)->i;
		else if ((*temp)->i > data->smallestnbr)
			data->smallestnbr = (*temp)->i;
	}
	else
	{
		*smallest = *tempm;
		data->smallestnbr = (*temp)->i;
	}
}

int		getsmallest(t_stack *stacka, t_stack *stackb, t_data *data)
{
	t_stack *temp;
	int		smallestmoves;
	int		tempmoves;

	temp = stacka;
	temp->prev->next = NULL;
	smallestmoves = numofmoves(stacka, stackb, temp->prev->i, data);
	data->smallestnbr = stacka->prev->i;
	while (temp)
	{
		tempmoves = numofmoves(stacka, stackb, temp->i, data);
		if (tempmoves <= smallestmoves)
		{
			normisbitch(&tempmoves, &smallestmoves, &temp, data);
		}
		temp = temp->next;
	}
	stacka->prev->next = stacka;
	return (data->smallestnbr);
}
