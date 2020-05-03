#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <math.h>

int fact(int n)
{
    if(n>1)
        return n*fact(n-1);
    else
        return 1;
}

void bezier(int px[], int py[], int n)
{
    float u,x,y,b;

    putpixel(px[0],py[0],WHITE);

    int nfact=fact(n-1);

    for(u=0.0001;u<1;u+=0.0001)
    {
        x=0;
        y=0;

        for(int i=0;i<n;i++)
        {
            b=(nfact*pow(1-u,n-1-i)*pow(u,i))/(fact(n-1-i)*fact(i));

            x+=b*px[i];
            y+=b*py[i];
        }

        putpixel(x,y,WHITE);
    }

    putpixel(px[n-1],py[n-1],WHITE);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	const int n = 3;
    int px[n],py[n];

    printf("Enter %d Points: ",n);

    for(int i=0;i<n;i++)
		scanf("%d %d",&px[i],&py[i]);

    bezier(px,py,n);

    getch();
    return 0;
}
