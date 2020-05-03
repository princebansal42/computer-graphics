#include <graphics.h>
#include <iostream.h>
#include <dos.h>
#include <conio.h>
void floodFill(int x, int y, int old, int fill)
{
    int current;
    current = getpixel(x, y);
    if (current == old)
    {
        putpixel(x, y, fill);
        delay(2);
        floodFill(x + 1, y, old, fill);
        floodFill(x - 1, y, old, fill);
        floodFill(x, y + 1, old, fill);
        floodFill(x, y - 1, old, fill);
    }
}

void main()
{
    int x, y, o = 0;
    int gDriver = DETECT, gmode;
    initgraph(&gDriver, &gmode, "c:\\turboc3\\bgi");
    rectangle(100, 100, 150, 200);
    x = (100 + 150) / 2;
    y = (100 + 200) / 2;
    floodFill(x, y, o, 4);
    getch();
    closegraph();
}