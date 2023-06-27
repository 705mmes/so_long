/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:09:38 by sammeuss          #+#    #+#             */
/*   Updated: 2023/06/27 13:30:26 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <stdbool.h>
# include "mlx/include/MLX42/MLX42.h"

# define TS 64

typedef struct s_exit
{	
	mlx_image_t	*img;
	int			x;
	int			y;
}		t_exit;

typedef struct s_collectibles
{
	mlx_image_t	*img;
	bool		is_collected;
	int			x;
	int			y;
}		t_collectibles;

typedef struct s_player
{
	mlx_image_t	*img;
	int			x;
	int			y;
	int			width;
	int			height;
	int			count_c;
}		t_player;

typedef struct s_map
{
	char	**array;
	int32_t	width;
	int32_t	height;
}		t_map;

typedef struct s_game
{
	t_collectibles	**c;
	mlx_t			*mlx;
	mlx_texture_t	**textures;
	t_map			*map;
	t_player		*p;
	t_exit			*e;
	int				score;
	mlx_image_t		*score_img;
	bool			game_on;
}		t_game;

// | map_parsing_0.c |

char			**map_init(char *map);
int				map_checker(char **map);
int				map_is_rectangle(char **map);
int				check_for_exit(char **map);
int				check_for_spawn(char **map);

// | map_parsing_1.c |
int				check_chars_in_map(char	**map);
int				check_for_collectibles(char **map);
int				map_is_closed(char **map);

// | map_is_possible.c |

int				final_check(char **map, int **array);
int				nb_possibilities(int **array, int count, char	**map);
int				check_sides(int	**array, int count, int i, int u);
int				map_is_possible(char **map);
int				**init_int_array(char **map);

// | parsing.c |

int				ft_array_len(char	**array);
int				ft_array_len_int(int	**array, char **map);
bool			check_ext(char	*file_name, char	*ext);
char			**ft_array_join(char **array, char *line);
char			*freeall(char **str);

// | utils.c |

int				check_hitbox(t_game *game, int x, int y);
int				nb_ct(char **map);
void			find_spawn(int	*i, int	*u, char **map);
int				check_hitbox_c(t_game	*g, int c_c, int p_x, int p_y);
void			free_char_array(char **array);

// |init_game_and_textures.c |

void			*init_game(void);
void			init_textures(t_game *game);
t_collectibles	*init_collectibles(t_game *g, int i, int u);
void			free_necessary(t_game *game);

// | draw.c |

void			draw_collectibles(char	**map, t_game	*g);
void			draw_map(char	**map, t_game *game);
void			draw_exit_and_player(char **map, t_game *g);

// | runnin.c |

void			start(t_game	*game);
void			main_hook(void *param);
void			collectibles_hook(void	*param);
void			ft_exit(t_game	*g, int counter);
void			move(t_game	*game, int choice);

// | free.c |

void			free_int_array(int	**array, char **map);
void			free_textures(t_game *game);
void			free_collectible(t_game *game);
void			free_map(t_game *game);
void			free_all(t_game *game);

// | so_long.c |

void			ft_score_hook(void *param);

// -> GNL

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char			*get_next_line(int fd);
char			*ft_strjoin_gnl(char *s1, char *s2, int *read_size, int i);
char			*ft_line(char *buffer, char *line, int *read_size);
char			*ft_read_backslash(char	*s, int fd, char *save, int *len_buff);
int				ft_strlen_gnl(char *s);
int				len_backslash_n(char *s, int *read_size, int choice);
int				ft_fill_save(char **save, int *read_size);
char			*free_item(char **s);
char			*double_free(char *s1, char **s2);
char			*gnl_v2(char **save, char **line, int *read_size, int *i);

#endif