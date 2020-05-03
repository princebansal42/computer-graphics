#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
void midPoint(int X1, int Y1, int X2, int Y2)
{
	int dx = X2 - X1;
	int dy = Y2 - Y1;
	int d = dy - (dx / 2);
	int x = X1, y = Y1;
	putpixel(x, y, WHITE);
	while (x < X2)
	{
		x++;
		if (d < 0)
			d = d + dy;
		else
		{
			d += (dy - dx);
			y++;
		}
		putpixel(x, y, WHITE);
	}
}
void main()
{
	int gd = DETECT, gm, X1, X2, Y1, Y2;
	initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
	cout << "Enter the starting point(x1,y1): " << endl;
	cin >> X1 >> Y1;
	cout << "Enter the end point(x2,y2): " << endl;
	cin >> X2 >> Y2;
	midPoint(X1, Y1, X2, Y2);
	getch();
}