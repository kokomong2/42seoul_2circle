/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:29:24 by sgo               #+#    #+#             */
/*   Updated: 2023/07/29 20:45:59 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "./LIBFT/libft.h"
// tester
# include <stdio.h>
typedef struct s_info
{
	int	*array;
	int	*stack_a;
	int	size_a;
	int	bottom_index_a;
	int	*stack_b;
	int	size_b;
	int	bottom_index_b;
	int	have_zero;
}		t_info;

void	ft_swap_a(t_info *info);
t_info	*ft_info_new(int size);
void	free_info(t_info *info);
void	print_error(void);
int		get_str_size(int argc, char *argv[]);
void	ft_argv_to_array(char *argv[], int array_size, t_info *info);
void	ft_ss(t_info *info);
void	ft_push_a(t_info *info);
void	ft_push_b(t_info *info);
void	ft_ra(t_info *info);
void	ft_rb(t_info *info);
void	ft_rr(t_info *info);
void	ft_rra(t_info *info);
void	ft_rrb(t_info *info);
void	ft_rrr(t_info *info);
void	array_sort(t_info *info, int array_size);
void	binary_search(t_info *info, int index, int low, int high);
void	indexing_stack_a(t_info *info);
char	**freeresult(size_t i, char **result);
void	get_pivot(t_info *info, int array_size);
void	ft_rotate_same(t_info *info, int *a, int *b);
void	ft_rotate_a(t_info *info, int a);
void	ft_rotate_b(t_info *info, int b);
int		ft_abs(int a);
void	greedy(t_info *info);
void	check_duplicate(t_info *info, int *array, int array_size, int check);
void	sort_three(t_info *info);
void	check_sorted(t_info *info, int array_size);
void	sort_short(t_info *info);
void	ft_twist_half(int *a_location, int *b_location, int size_a, int size_b);
int		is_all_blank(char *str);

#endif