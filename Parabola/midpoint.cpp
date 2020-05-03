#include<iostream.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
void put_pixel(int x, int y)
{
	putpixel((x+300),(240-y),15);
	putpixel((x+300),(240+y),15);
}
void para(int cx, int cy, double a)
{
	setcolor(BLUE);
	line(300,0,300,479);
	setcolor(RED);
	line(0,240,639,240);
	double x=0,y=0;  /* initial coorodinates */
	double d1;
	d1=(2*a - 1);
	put_pixel(x,y);
	while(y<= (2*a*1.0))
	{
		if(d1<0)
		{
			d1+= 4*a-3-2*y;
			x++;
			y++;
		}
		else
		{
			d1-= 3 + 2*y;
			y++;
		}
		put_pixel(x,y);
	}
	d1=((4.0*a*(x+1))-(y+0.5)*(y+0.5));
	while( y < 220 )
	{
		if(d1<0)
		{
			d1+= 4*a;
			x++;
		}
		else
		{
			d1+=((4.0*a)-(2.0*y)-2);
			x++;
			y++;
		}
		put_pixel(x,y);
	}
}
int main()
{
	double a;
	cout<<"Enter a : ";
	cin>>a;
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
	para(0,0,a);
	getch();
	closegraph();
	return 0;
}
