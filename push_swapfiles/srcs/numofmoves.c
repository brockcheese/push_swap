/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numofmoves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 23:34:08 by bpace             #+#    #+#             */
/*   Updated: 2019/09/24 23:56:10 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	numofmovesa(t_stack *stacka, int nbr, t_data *data)
{
	int		up;
	int		down;
	t_stack *temp;

	down = 0;
	up = 0;
	temp = stacka;
	while (temp->i != nbr)
	{
		down++;
		temp = temp->next;
	}
	temp = stacka;
	while (temp->i != nbr && up <= down)
	{
		up++;
		temp = temp->prev;
	}
	data->au = (down <= up) ? 0 : 1;
	data->a = (down <= up) ? down : up;
}

int		numofmovesans(int up, int down, t_data *data)
{
	int		ans;

	if (down <= up)
	{
		data->bu = 0;
		data->b = down;
	}
	else
	{
		data->bu = 1;
		data->b = up;
	}
	if (data->au == data->bu)
		ans = (data->a >= data->b) ? data->a : data->b;
	else
		ans = data->a + data->b;
	return (ans);
}

void	numofmovesb(t_stack *stackb, int nbr, int *down, int *up)
{
	t_stack	*temp;

	temp = stackb;
	while (!(temp->i < nbr && temp->prev->i > nbr))
	{
		(*down)++;
		temp = temp->next;
	}
	temp = stackb;
	while (!(temp->i < nbr && temp->prev->i > nbr))
	{
		(*up)++;
		temp = temp->prev;
	}
}

int		numofmoves(t_stack *stacka, t_stack *stackb, int nbr, t_data *data)
{
	int		up;
	int		down;
	t_stack	*temp;

	numofmovesa(stacka, nbr, data);
	down = 0;
	up = 0;
	temp = stackb;
	if (nbr > data->max || nbr < data->min)
	{
		while (temp->i != data->max)
		{
			down++;
			temp = temp->next;
		}
		temp = stackb;
		while (temp->i != data->max && up <= down)
		{
			up++;
			temp = temp->prev;
		}
	}
	else
		numofmovesb(stackb, nbr, &down, &up);
	return (numofmovesans(up, down, data));
}
