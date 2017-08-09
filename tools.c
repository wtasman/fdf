#include "fdf.h"

void	copy_mat(float	source[4][4], float dest[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dest[i][j] = source[i][j];
			j++;
		}
		i++;
	}
}

void	multiply_matrix(float mat1[4][4], float mat2[4][4], float dest[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dest[i][j] = mat1[i][0] * mat2[0][j] + mat1[i][1] * mat2[1][j] + 
							mat1[i][2] * mat2[2][j] + mat1[i][3] * mat2[3][j];
			j++;
		}
		i++;
	}
}

void	mult_mat_vec(t_3d *source, float matrix[4][4], t_3d *dest)
{
	dest->x = source->x * mat[0][0] + source->y * mat[1][0] + source->z * 
		mat[2][0] + mat[3][0];
	dest->y = source->x * mat[0][1] + source->y * mat[1][1] + source->z * 
		mat[2][1] + mat[3][1];
	dest->z = source->x * mat[0][2] + source->y * mat[1][2] + source->z * 
		mat[2][2] + mat[3][2];
}
