#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}
void main()
{
	int gd = DETECT, gm, x1, x2, y1, y2, dx, dy, p, k;
	initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
	float m = 0;
	printf("Enter the starting point (x1,y1)\n");
	scanf("%d%d", &x1, &y1);
	printf("Enter the end point (x2,y2)\n");
	scanf("%d%d", &x2, &y2);
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	m = (float)(y2 - y1) / (x2 - x1);
	if (fabs(m) > 1)
	{
		swap(x1, y1);
		swap(x2, y2);
		swap(dx, dy);
	}
	if ((x1 > x2))
	{
		x1 = x2;
		y1 = y2;
	}
	p = 2 * dy - dx;
	for (k = 0; k < abs(dx); k++)
	{
		if (p < 0)
		{
			p = p + 2 * dy;
		}
		else
		{
			if (m < 0)
				y1--;
			else
				y1++;
			p = p + (2 * dy) - (2 * dx);
		}
		if (fabs(m) <= 1)
			putpixel(x1++, y1, 15);
		else
			putpixel(y1, x1++, 15);
	}
	getch();
	closegraph();
}
