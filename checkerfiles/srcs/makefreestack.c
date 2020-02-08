/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makefreestack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:27:09 by bpace             #+#    #+#             */
/*   Updated: 2019/09/24 23:22:17 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int			makestacktwo(char **argc, t_stack **begin, int v, int *ij)
{
	t_stack		*temp;
	long long	error;

	while (--ij[0] > v - 1)
	{
		temp = *begin;
		*begin = malloc(sizeof(t_stack));
		error = ft_atolonglong(argc[ij[0]]);
		ij[1] = (error > INT_MAX || error < INT_MIN) ? 0 : ij[1];
		(*begin)->i = (int)error;
		(*begin)->next = temp;
		if (temp != NULL)
			temp->prev = *begin;
		while (temp)
		{
			ij[1] = (temp->i == (*begin)->i) ? 0 : ij[1];
			temp = temp->next;
		}
	}
	temp = *begin;
	while (temp && temp->next)
		temp = temp->next;
	(*begin)->prev = temp;
	temp->next = *begin;
	return (ij[1]);
}

int			makestack(char **argc, t_stack **begin, int v)
{
	int			ij[2];

	ij[0] = (v == 1) ? 0 : -1;
	while (argc[++ij[0]])
	{
		ij[1] = -1;
		while (argc[ij[0]][++ij[1]])
		{
			if ((!(ft_isdigit(argc[ij[0]][ij[1]])) &&
			argc[ij[0]][0] != '-' && argc[ij[0]][0] != '+') || ij[1] > 11)
				return (0);
		}
	}
	ij[1] = (v == 1) ? ij[0] - 1 : ij[0];
	return (makestacktwo(argc, begin, v, ij));
}

void		freestack(t_stack **begin)
{
	t_stack *temp;

	if (*begin)
		(*begin)->prev->next = NULL;
	while (*begin)
	{
		temp = (*begin)->next;
		free(*begin);
		*begin = temp;
	}
}
