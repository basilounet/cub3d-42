/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:32:54 by bvasseur          #+#    #+#             */
/*   Updated: 2024/06/07 18:45:43 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	launch_mlx(t_cub *cb)
{
	cb->player.pos = set_vector(5, 5);
//	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	cb->mlx = mlx_init(WIDTH, HEIGHT, "3dcub", false);
	cb->image = mlx_new_image(cb->mlx, WIDTH, HEIGHT);
	cb->minimap = mlx_new_image(cb->mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	mlx_image_to_window(cb->mlx, cb->image, 0, 0);
	mlx_image_to_window(cb->mlx, cb->minimap, 0, 0);
    ft_memset(cb->image->pixels, 0xFFFFFFFF, cb->image->height * cb->image->width * 4);
	mlx_key_hook(cb->mlx, ft_key_hook, cb);
	mlx_loop_hook(cb->mlx, ft_loop_hook, cb);
	
	ft_printf("height : %d, widht %d\n", cb->map.height, cb->map.widht);
	
	mlx_loop(cb->mlx);
	mlx_delete_image(cb->mlx, cb->image);
	mlx_terminate(cb->mlx);	
}

int32_t main(void)
{
	t_cub	cb;
	
	parse(&cb);
	launch_mlx(&cb);
	unleak(&cb);
	return (0);
}
