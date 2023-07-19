/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:29:24 by sgo               #+#    #+#             */
/*   Updated: 2023/07/14 19:40:29 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "./LIBFT/libft.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	int				content;
	struct s_stack	*next;
}		t_stack;

typedef struct s_info
{
	int				*array;
	int				size_a;
	struct s_stack	*top_a;
	struct s_stack	*bottom_a;
	int				size_b;
	struct s_stack	*top_b;
	struct s_stack	*bottom_b;
}		t_info;

t_stack	*ft_newstack(int content);
void	ft_swap_a(t_info *info);
t_info	*ft_info_new();
void 	print_error(int type);
int		get_str_size(int argc, char *argv[]);
int		*ft_argv_to_array(char *argv[], int array_size);
t_stack	*ft_push(t_stack **stack, int content);
void	ft_arr_to_stack(t_info *info,int *num_array, int array_size);
// test
#include <stdio.h>
void print_stack(t_info *info);
//test
#endif