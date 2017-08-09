#include "fdf.h"

void	mat_x(float mat[4][4], x)
{
	xmat[0][0] = 1;
	xmat[0][1] = 0;
	xmat[0][2] = 0;
	xmat[0][3] = 0;
   	xmat[1][0] = 0;
   	xmat[1][1] = cos(x);
   	xmat[1][2] = sin(x);
   	xmat[1][3] = 0;
   	xmat[2][0] = 0;
   	xmat[2][1] = -sin(x);
   	xmat[2][2] = cos(x);
   	xmat[2][3] = 0;
   	xmat[3][0] = 0;
   	xmat[3][1] = 0;
   	xmat[3][2] = 0;
   	xmat[3][3] = 1;
}

void	mat_y(float mat[4][4], y)
{
   	ymat[0][0] = cos(y);
   	ymat[0][1] = 0;
   	ymat[0][2] = -sin(y);
   	ymat[0][3] = 0;
   	ymat[1][0] = 0;
   	ymat[1][1] = 1;
   	ymat[1][2] = 0;
   	ymat[1][3] = 0;
   	ymat[2][0] = sin(y);
   	ymat[2][1] = 0;
   	ymat[2][2] = cos(y);
   	ymat[2][3] = 0;
   	ymat[3][0] = 0;
   	ymat[3][1] = 0;
   	ymat[3][2] = 0;
   	ymat[3][3] = 1;
}

void	mat_z(float mat[4][4], z)
{
   	zmat[0][0] = cos(z);
   	zmat[0][1] = sin(z);
   	zmat[0][2] = 0;
   	zmat[0][3] = 0;
   	zmat[1][0] = -sin(z);
   	zmat[1][1] = cos(z);
   	zmat[1][2] = 0;
   	zmat[1][3] = 0;
   	zmat[2][0] = 0;
   	zmat[2][1] = 0;
   	zmat[2][2] = 1;
   	zmat[2][3] = 0;
   	zmat[3][0] = 0;
   	zmat[3][1] = 0;
   	zmat[3][3] = 1;
}

void	rotate_mat(float matrix[4][4], int x, int y, int z)
{
	float	xmat[4][4];
	float	ymat[4][4];
	float	zmat[4][4];

	mat_x(xmat, x);
	mat_y(ymat, y);
	mat_z(zmat, z);
	mulitply_mat(matrix, ymat, mat1);
	mulitply_mat(mat1, xmat, mat2);
	multiply_mat(mat2, zmat, matrix);
}
