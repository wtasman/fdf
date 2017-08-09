#include "fdf.h"

float	sintab[256];
float	costab[256];

#define pi 3.141593
#define ABS(x)	((x) < 0 ? -(x) : (x))
#define SIN(x) sintab[abs((int)x&255)]
#define COS(x)	costab[abs((int)x&255)]

void	create_trig_tables(void)
{
	int	d;

	d = 0;
	while (d < 256)
	{
		sintab[d] = sin(d * pi / 128.0)
		costab[d] = cos(d * pi / 128.0)
		d++;
	}
}