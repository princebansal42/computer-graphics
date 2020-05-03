#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
void main()
{
	clrscr();
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
	//line(20,20,10,10);
	//putpixel(100,100,WHITE);
	int x1, x2, y1, y2;
	cout << "Enter the coordinates of the first point(x1,y1)" << endl;
	cin >> x1 >> y1;
	cout << "Enter the coordinates of the second point(x2,y2)" << endl;
	cin >> x2 >> y2;
	int dx = x2 - x1;
	int dy = y2 - y1;
	float x = x1;
	float y = y1;
	float m1 = (1.0 * dy) / dx;
	float m2 = (1.0 * dx) / dy;
	putpixel(x, y, WHITE);
	if (dx > dy)
	{
		while (x <= x2)
		{
			x++;
			y += m1;
			putpixel(x, y, WHITE);
		}
	}

	else
	{
		while (y <= y2)
		{
			y++;
			x += m2;
			putpixel(x, y, WHITE);
		}
	}
	getch();
	closegraph();
}