#include "paint.h"

int main(int ac, char **av)
{
	FILE	*stream;
	int	n_byte;
	int		zone_X, zone_Y, rect_X, rect_Y;
	float	Xlt, Ylt;
	char	bg_symb, type_of_rect, rect_symb;
	
	if (ac != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	stream = fopen(av[1], "r");
	n_byte = fscanf(stream, " %d %d %c %c %f %f %d %d %c", &zone_X, &zone_Y, &bg_symb,
					&type_of_rect, &Xlt, &Ylt, &rect_X, &rect_Y, &rect_symb);
	(void)n_byte;
	int	x;
	int	y = 0;
	float Xrt = Xlt + rect_X; float Yrt = Ylt;
	float Xlb = Xlt; float Ylb = Ylt + rect_Y;
	float Xrb = Xrt; float Yrb = Ylb;

	while (y != zone_Y)
	{
		x = 0;
		while (x <= zone_X)
		{
			if (x == zone_X)
			{
				write(1, "\n", 1);
				break ;
			}
			if (Xlt <= (float)x && (float)x <= Xrb 
				&& Ylt <= (float)y && (float)y <= Yrb)
			{
				if (type_of_rect == 'R')
				{				
					if ((float)x - Xrt < 1 || Xrt - (float)x < 1 
						|| (float)y - Ylb < 1 || Ylb - y < 1)
						write(1, &rect_symb, 1);
				}
				if (type_of_rect == 'r')
				{
					if (((x - Xlt < 1.00000000) || ((Xlt + rect_X) - x < 1.00000000)) ||
						((y - Ylt < 1.00000000 || ((Ylt + rect_Y) - y < 1.00000000))))
						write(1, &rect_symb, 1);
					else
						write(1, &bg_symb, 1);
				}
			}
			else
				write(1, &bg_symb, 1);
			x++;
		}
		y++;
	}
	fclose(stream);
	return (0);
}