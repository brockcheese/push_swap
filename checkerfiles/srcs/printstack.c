/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:24:59 by bpace             #+#    #+#             */
/*   Updated: 2019/09/25 18:43:21 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int		numlen(int num)
{
	if (num < 0)
		return (1 + numlen(-(num)));
	if (num >= 10)
		return (1 + numlen(num / 10));
	return (1);
}

void	printstackelem(t_stack *stacka, t_stack *stackb)
{
	t_stack *tempa;
	t_stack *tempb;

	tempa = stacka;
	tempb = stackb;
	while (tempa || tempb)
	{
		if (tempa)
		{
			ft_printf("%d", tempa->i);
			tempa = tempa->next;
		}
		else
			write(1, " ", 1);
		write(1, " ", 1);
		if (tempb)
		{
			ft_printf("%d", tempb->i);
			tempb = tempb->next;
		}
		write(1, "\n", 1);
	}
	write(1, "_ _\na b\n", 8);
}

void	printstack(t_stack *stacka, t_stack *stackb)
{
	if (stacka)
		stacka->prev->next = NULL;
	if (stackb)
		stackb->prev->next = NULL;
	printstackelem(stacka, stackb);
	if (stacka)
		stacka->prev->next = stacka;
	if (stackb)
		stackb->prev->next = stackb;
}
