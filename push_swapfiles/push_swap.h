/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:31:36 by bpace             #+#    #+#             */
/*   Updated: 2019/09/26 02:25:37 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../checkerfiles/checker.h"

typedef struct		s_data
{
	int				a;
	int				b;
	int				v;
	int				au;
	int				bu;
	int				max;
	int				min;
	int				size;
	int				smallest;
	int				smallestnbr;
}					t_data;

void				getmaxmin(t_stack *stacka, t_data *data);
void				numofmovesa(t_stack *stacka, int nbr, t_data *data);
int					getsmallest(t_stack *stacka, t_stack *stackb,
					t_data *data);
int					numofmoves(t_stack *stacka, t_stack *stackb, int nbr,
					t_data *data);
void				quicksort(t_stack **stacka, t_stack **stackb,
					t_data *data, int *fd);
void				sortfive(t_stack **stacka, t_stack **stackb,
					t_data *data, int *fd);
void				sortsmallest(t_stack **stacka, t_stack **stackb,
					t_data *data, int *fd);
void				sortthree(t_stack **stacka, t_stack **stackb,
					t_data *data, int *fd);

#endif
