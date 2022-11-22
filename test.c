#include "ft_printf/ft_printf.h"
#include "mlx/mlx/mlx.h"
#include "mlx/mlx/mlx_int.h"
#include "solong.h"
#include <time.h>

int main()
{
	void *mlx;
	void *img;
	void *win;
	int a, b;

	img = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 100, 100, "ok");
	img = mlx_xpm_file_to_image(mlx, "./sprites/wallnamek.xpm", &a, &b);
	if (!img)
		return 0;
	mlx_put_image_to_window(mlx, win, img, 25, 25);
	mlx_destroy_image(mlx, img);
   mlx_clear_window(mlx, win);
   mlx_destroy_window(mlx,win);
	mlx_destroy_display(mlx);
	free(mlx);
}