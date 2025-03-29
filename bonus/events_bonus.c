/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclee <niclee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 11:44:32 by niclee            #+#    #+#             */
/*   Updated: 2025/03/22 11:44:32 by niclee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	handle_key(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
		close_win(fractal);
	else if (keycode == 65362)
		fractal->offset_y -= 0.1 * fractal->zoom;
	else if (keycode == 65364)
		fractal->offset_y += 0.1 * fractal->zoom;
	else if (keycode == 65361)
		fractal->offset_x -= 0.1 * fractal->zoom;
	else if (keycode == 65363)
		fractal->offset_x += 0.1 * fractal->zoom;
	else if (keycode == 65451)
		fractal->max_iter += 10;
	else if (keycode == 65453 && fractal->max_iter > 10)
		fractal->max_iter -= 10;
	else if (keycode >= 49 && keycode <= 54)
		fractal->color_scheme = keycode - 49;
	render_fractal(fractal);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;
	double	scale_x;
	double	scale_y;

	scale_x = (4.0 / WIDTH) * fractal->zoom;
	scale_y = (4.0 / HEIGHT) * fractal->zoom;
	mouse_re = (x - WIDTH / 2) * scale_x + fractal->offset_x;
	mouse_im = (y - HEIGHT / 2) * scale_y + fractal->offset_y;
	if (button == 4)
	{
		fractal->zoom *= 0.9;
		fractal->offset_x = mouse_re - (mouse_re - fractal->offset_x) * 0.9;
		fractal->offset_y = mouse_im - (mouse_im - fractal->offset_y) * 0.9;
	}
	else if (button == 5)
	{
		fractal->zoom *= 1.1;
		fractal->offset_x = mouse_re - (mouse_re - fractal->offset_x) * 1.1;
		fractal->offset_y = mouse_im - (mouse_im - fractal->offset_y) * 1.1;
	}
	render_fractal(fractal);
	return (0);
}
