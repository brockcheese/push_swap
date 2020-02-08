/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:34:26 by bpace             #+#    #+#             */
/*   Updated: 2019/09/26 01:23:48 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		sort(t_stack **begin, t_data *data, int *fd)
{
	t_stack		*stackb;

	stackb = NULL;
	if (data->v == 1)
		printstack(*begin, stackb);
	if (!checkbegin(*begin, data->size))
	{
		if (data->size <= 3)
			sortthree(begin, &stackb, data, fd);
		else if (data->size <= 5)
			sortfive(begin, &stackb, data, fd);
		else
			quicksort(begin, &stackb, data, fd);
	}
	freestack(begin);
}

char		**pushswapinit(int *fd, int argc, char ***argv)
{
	char **ans;

	if (argc == 2)
		*argv = ft_strsplit((*argv)[0], ' ');
	fd[0] = open((*argv)[0], O_RDWR);
	if (fd[0] == -1)
	{
		fd[0] = 0;
		fd[1] = 1;
		ans = *argv;
	}
	else
	{
		fd[1] = fd[0];
		ans = *argv + 1;
	}
	return (ans);
}

void		freeargv(int argc, char **argv)
{
	int		i;

	if (argc == 2)
	{
		i = -1;
		while (argv[++i])
			ft_strdel(&argv[i]);
		free(argv);
	}
}

int			pushswap(int argc, char **argv)
{
	t_stack		*begin;
	t_data		*data;
	char		**argvtemp;
	int			fd[2];

	begin = NULL;
	data = malloc(sizeof(t_data));
	data->v = 0;
	argvtemp = pushswapinit(fd, argc, &argv);
	if (!(ft_strcmp(argvtemp[0], "-v")))
		data->v++;
	if (!(data->size = makestack(argvtemp, &begin, data->v)))
	{
		freestack(&begin);
		freeargv(argc, argv);
		write(fd[1], "Error\n", 6);
		close(fd[0]);
		free(data);
		return (0);
	}
	sort(&begin, data, fd);
	freeargv(argc, argv);
	close(fd[0]);
	free(data);
	return (1);
}

int			main(int argc, char **argv)
{
	if (argc > 1)
		pushswap(argc, argv + 1);
	return (0);
}
