/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 12:26:26 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/06/07 19:07:02 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "ft_printf.h"

typedef struct			s_anthill
{
	char				*name;
	int					start;
	int					end;
	int					x;
	int					y;
	int					number;
	int					used;
	struct s_tubes		*tubes;
	struct s_anthill	*next;
	struct s_anthill	*first;
	struct s_anthill	*last;
}						t_anthill;

typedef struct			s_tubes
{
	t_anthill			*room;
	struct s_tubes		*next;
}						t_tubes;

typedef struct			s_room
{
	char				*name;
	int					ant;
	int					number;
	struct s_room		*next;
}						t_room;

typedef struct			s_paths
{
	t_room				*room;
	struct s_paths		*next;
}						t_paths;

typedef struct			s_ants
{
	int					name;
	t_room				*room;
}						t_ants;

t_anthill				*get_room(char **input, t_anthill *room, int start,
		int end);
int						check_tube(char *str, int i, t_anthill *room);
void					free_split(char **split);
void					error_room();
t_anthill				*init_n(t_anthill *new, char **split, int start,
		int end);
void					check_data(t_anthill *room);
void					solve(t_anthill *room, t_paths **paths);
t_room					*create_elem(t_room *path, char *name, int number);
void					elem_next(t_room *tmp, t_room *new, char *name,
		int number);
t_anthill				*search_tmp2(t_anthill *start);
void					delete_path(t_room **path);
t_paths					*init_new(void);
void					path_error(void);
void					move_ants(t_paths *paths, int ants, char **av);
void					check_details(t_ants *ants, int ants_nbr, char **argv);
char					*ft_strjoin_free_both(char const *s1, char const *s2);
void					check_help(int ac, char **av);
void					check_bonus(t_anthill *rooms, t_paths *paths,
		char **av);

#endif
