#include "fdf.h"

void	project(t_vertex *vertex)
{
	if (!vertex->aligned.z)
		vertex->aligned.z = 1;
	vertex->screen.x = distance * vertex->aligned.x / vertex->aligned.z + xo;
	vertex->screen.y = distance * vertex->aligned.y / vertex->aligned.z + yo;
}

void	transform(vertex)
{
	make_trig_tables();
	identity_mat(matrix);
	scale_mat(matrix, vertex->x, vertex->y, vertex->z);
	rotate_mat(matrix, vertex->x, vertex->y, vertex->z);
	translate_mat(matrix, vertex->x, vertex->y, vertex->z);
	mult_mat_vec(vertex->local, matrix, vertex->world);
	identity_mat(matrix);	
}