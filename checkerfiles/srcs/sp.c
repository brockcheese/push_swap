/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:19:11 by bpace             #+#    #+#             */
/*   Updated: 2019/09/24 01:13:41 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rr(t_stack **begin)
{
	if (*begin)
		*begin = (*begin)->prev;
}

void	r(t_stack **begin)
{
	if (*begin)
		*begin = (*begin)->next;
}

void	ptwo(t_stack **stack1, t_stack *temp)
{
	if (!*stack1)
	{
		*stack1 = temp;
		(*stack1)->next = *stack1;
		(*stack1)->prev = *stack1;
	}
	else
	{
		temp->next = *stack1;
		temp->prev = (*stack1)->prev;
		temp->prev->next = temp;
		(*stack1)->prev = temp;
		*stack1 = temp;
	}
}

void	p(t_stack **stack1, t_stack **stack2)
{
	t_stack		*temp;

	temp = NULL;
	if (*stack2)
	{
		temp = *stack2;
		if (temp->next == temp)
			*stack2 = NULL;
		else
		{
			*stack2 = temp->next;
			(*stack2)->prev = temp->prev;
			(*stack2)->prev->next = *stack2;
		}
		ptwo(stack1, temp);
	}
}

void	s(t_stack **begin)
{
	t_stack		*temp;

	if (*begin && (*begin)->next)
	{
		if ((*begin)->prev->i == (*begin)->next->i)
			r(begin);
		else
		{
			temp = (*begin)->next;
			(*begin)->prev->next = temp;
			temp->next->prev = *begin;
			(*begin)->next = temp->next;
			temp->prev = (*begin)->prev;
			(*begin)->prev = temp;
			temp->next = *begin;
			*begin = temp;
		}
	}
}
