/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:09:38 by sammeuss          #+#    #+#             */
/*   Updated: 2023/05/31 12:11:36 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <stdbool.h>
# include "mlx/include/MLX42/MLX42.h"

# define T_S 64

typedef struct s_player
{
	mlx_image_t	*img;
	int			x;
	int			y;
	int			width;
	int			height;
}		t_player;

typedef struct s_map
{
	char	**array;
	int32_t	width;
	int32_t	height;
}		t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_texture_t	**textures;
	t_map			*map;
	t_player		*p;
}		t_game;

// | map_parsing_0.c |

int		map_is_rectangle(char **map);
int		map_checker(char **map);
char	**map_init(char *map);
int		check_for_spawn(char **map);
int		check_for_exit(char **map);

// | map_parsing_1.c |
int		check_for_collectibles(char **map);
int		map_is_closed(char **map);
int		**init_int_array(char **map);
int		map_is_possible(char **map, int **array);

// | parsing.c |

int		ft_error(void);
bool	check_ext(char	*file_name, char	*ext);
char	**ft_array_join(char **array, char *line);
int		ft_array_len(char	**array);

// | utils.c |

void	print_char_array(char **array);
void	print_int_array(int **array);
void	find_spawn(int	*i, int	*u, char **map);
int		how_many_collectibles(char **map);
int		check_hitbox(t_game *game, int	x, int	y);

// |init_game_and_textures.c |

void	*init_game(void);
void	init_textures(t_game *game);
void	start(t_game	*game);
void	draw_map(char	**map, t_game *game);
void	draw_collectibles_exit_and_player(char **map, t_game *g);

// | hooks.c |

void	hook(void *param);

// -> GNL

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2, int *read_size, int i);
char	*ft_line(char *buffer, char *line, int *read_size);
char	*ft_read_until_backslash_n(char	*s, int fd, char *save, int *len_buff);
int		ft_strlen_gnl(char *s);
int		len_backslash_n(char *s, int *read_size, int choice);
int		ft_fill_save(char **save, int *read_size);
char	*free_item(char **s);
char	*double_free(char *s1, char **s2);
char	*gnl_v2(char **save, char **line, int *read_size, int *i);

#endif