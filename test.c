#include "mlx.h"

int	main(void)
{
	void	*m_ptr;
	void	*w_ptr;

	m_ptr = mlx_init();
	w_ptr = mlx_new_window(m_ptr, 1200, 800, "test window");
	mlx_pixel_put(m_ptr, w_ptr, 250, 250, 0xFFFFFF);
	mlx_loop(m_ptr);
	return (0);
}