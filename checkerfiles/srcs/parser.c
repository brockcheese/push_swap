/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:40:21 by bpace             #+#    #+#             */
/*   Updated: 2019/09/24 01:13:42 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int			rotations(char *command, t_stack **stacka, t_stack **stackb)
{
	if (!(ft_strcmp(command, "ra")))
		r(stacka);
	else if (!(ft_strcmp(command, "rb")))
		r(stackb);
	else if (!(ft_strcmp(command, "rr")))
	{
		r(stacka);
		r(stackb);
	}
	else if (!(ft_strcmp(command, "rra")))
		rr(stacka);
	else if (!(ft_strcmp(command, "rrb")))
		rr(stackb);
	else if (!(ft_strcmp(command, "rrr")))
	{
		rr(stacka);
		rr(stackb);
	}
	else
		return (0);
	return (1);
}

int			bonus(char *command, t_stack **stacka, t_stack **stackb)
{
	t_stack *temp;

	if (!(ft_strcmp(command, "pp")))
	{
		p(stacka, stackb);
		r(stacka);
		p(stackb, stacka);
		rr(stacka);
	}
	else if (!(ft_strcmp(command, "swap")))
	{
		temp = *stacka;
		*stacka = *stackb;
		*stackb = temp;
	}
	else if (!(ft_strcmp(command, "ps")))
		printstack(*stacka, *stackb);
	else
		return (0);
	return (1);
}

int			execute(char *command, t_stack **stacka, t_stack **stackb)
{
	if (!(ft_strcmp(command, "sa")))
		s(stacka);
	else if (!(ft_strcmp(command, "sb")))
		s(stackb);
	else if (!(ft_strcmp(command, "ss")))
	{
		s(stacka);
		s(stackb);
	}
	else if (!(ft_strcmp(command, "pa")))
		p(stacka, stackb);
	else if (!(ft_strcmp(command, "pb")))
		p(stackb, stacka);
	else if (bonus(command, stacka, stackb))
		;
	else if (rotations(command, stacka, stackb))
		;
	else
		return (0);
	return (1);
}

int			parser(t_stack **begin, int v, int *fd)
{
	char	*command;
	t_stack	*stackb;

	stackb = NULL;
	if (v == 1)
		printstack(*begin, stackb);
	while (get_next_line(fd[0], &command))
	{
		if (!(execute(command, begin, &stackb)))
		{
			freestack(begin);
			freestack(&stackb);
			ft_strdel(&command);
			return (0);
		}
		else if (v == 1)
			printstack(*begin, stackb);
		ft_strdel(&command);
	}
	freestack(&stackb);
	return (1);
}
