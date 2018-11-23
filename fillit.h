/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:41:41 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/23 15:34:45 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_tetri
{
	int			tab[2][19];
	int			edge;
	int			pcs;
	int			i;
	char		*tetri;
	char		**t_base;
	char		**base;
	char		**tetri_block;
	char		**square;
}				t_tetri;

int				ft_put_tetri_in_sq(t_tetri *stock_t,
				int x, int y, int pcs);
int				ft_del_tetri_in_sq(char **square, char c);
void			ft_calc_edge(t_tetri *stock_tetri, int sizeplus);
int				ft_backtrack(t_tetri *stock_t, int pcs);
int				ft_count_tetri(t_tetri *stock_tetri);
int				ft_check_line(char *str, int nb_tetri, int nb_line);
int				ft_check_dim(char *str, int i, int n, int x);
int				ft_check_dim2(char *str);
void			ft_check_end_input(char *str);
void			ft_check_input(char *str);
void			ft_check_char(char *str);
void			ft_print_square(char **square);
void			ft_resolve(t_tetri *stock_tetri);
void			ft_cut_to_tetri(char **tetri);
void			ft_set_stock_to_zero(t_tetri *stock_tetri);
void			ft_error(void);
void			ft_error_str(char **str);
void			ft_error_tab(char ***str);
void			ft_error_tab_str(char ***str, char **str2);
void			ft_error_struct(t_tetri *stock_t);
void			ft_error_struct_tab(t_tetri *stock_t, char ***tab);
void			ft_error_struct_str(t_tetri *stock_t, char **str);
void			ft_error_struct_str_str(t_tetri *stock_t, char **str,
				char **str2);
void			ft_error_struct_str_str_str(t_tetri *stock_t, char **str,
				char **str2, char **str3);
void			ft_sqdel(char ***square);
void			ft_maincheck(char *str);
void			ft_set_square(t_tetri *stock_t, int sizeplus);
char			*ft_set_in_one_line(char *str);
char			**ft_set_tab_point(char **square, int square_size);
char			**ft_init_tetri_base_for_put(void);
char			**ft_init_tetri_base(void);
t_tetri			*ft_read_file(t_tetri *stock_t, char *flnme);
t_tetri			*ft_swap_nl_to_x(t_tetri *stock_t);
t_tetri			*ft_parsing(t_tetri *stock_t, int set_order);
t_tetri			*ft_check_match(char *tetri, char **tetri_base,
				t_tetri *stock_tetri);

#endif
