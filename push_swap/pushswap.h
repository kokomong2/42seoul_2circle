/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:29:24 by sgo               #+#    #+#             */
/*   Updated: 2023/07/20 18:15:26 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "./LIBFT/libft.h"

typedef struct s_info
{
	int	*array;
	int	*stack_a;
	int bottom_index_a;
	int	top_index_a;
	int	*stack_b;
	int bottom_index_b;
	int	top_index_b;
}		t_info;

void	ft_swap_a(t_info *info);
t_info	*ft_info_new(int size);
void 	print_error(int type);
int		get_str_size(int argc, char *argv[]);
void	ft_argv_to_array(char *argv[], int array_size, t_info	*info);
void	ft_ss(t_info *info);
void	ft_push_a(t_info *info);
void	ft_push_b(t_info *info);
void	ft_rotate_a(t_info *info);
void	ft_rotate_b(t_info *info);
void	ft_rr(t_info *info);
void	ft_reverse_a(t_info *info);
void	ft_reverse_b(t_info *info);
void	ft_rrr(t_info *info);
void	array_sort(t_info *info, int array_size);
void	binary_search(t_info *info, int index, int low, int high);
void	indexing_stack_a(t_info *info);
char	**freeresult(size_t i, char **result);
void	get_pivot(t_info *info, int array_size);

// test
#include <stdio.h>
void print_stack(t_info *info);
void print_array(t_info *info, int array_size);
//test
#endif