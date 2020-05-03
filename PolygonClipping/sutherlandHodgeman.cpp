#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <math.h>

int LeftResultX[30];
int LeftResultY[30];

int TopResultX[30];
int TopResultY[30];

int RightResultX[30];
int RightResultY[30];

int BottomResultX[30];
int BottomResultY[30];

int xmin = 20, ymin = 40, xmax = 100, ymax = 100;

int LeftClip(int x[], int y[], int n)
{
    int s = 0, j;
    for (int i = 0; i < n; i++)
    {
        j = (i + 1) % (n);
        if (x[i] < xmin && x[j] >= xmin)
        {
            LeftResultX[s] = xmin;
            LeftResultY[s] = y[i] + (xmin - x[i]) * (y[j] - y[i]) / (x[j] - x[i]);
            s++;
        }
        else if (x[i] < xmin && x[j] < xmin)
        {
            continue;
        }
        else if (x[i] >= xmin && x[j] < xmin)
        {
            LeftResultX[s] = x[i];
            LeftResultY[s] = y[i];
            s++;
            LeftResultX[s] = xmin;
            LeftResultY[s] = y[j] + (xmin - x[j]) * (y[j] - y[i]) / (x[j] - x[i]);
            s++;
        }
        else if (x[i] >= xmin && x[j] >= xmin)
        {
            LeftResultX[s] = x[i];
            LeftResultY[s] = y[i];
            s++;
        }
    }
    return s;
}

int TopClip(int x[], int y[], int n)
{
    int s = 0, j;
    for (int i = 0; i < n; i++)
    {
        j = (i + 1) % n;
        if (y[i] > ymax && y[j] <= ymax)
        {
            TopResultX[s] = x[i] + (ymax - y[i]) * (x[j] - x[i]) / (y[j] - y[i]);
            TopResultY[s] = ymax;
            s++;
        }
        else if (y[i] > ymax && y[j] > ymax)
        {
            continue;
        }
        else if (y[i] <= ymax && y[j] > ymax)
        {
            TopResultX[s] = x[i];
            TopResultY[s] = y[i];
            s++;
            TopResultX[s] = x[j] + (ymax - y[j]) * (x[j] - x[i]) / (y[j] - y[i]);
            TopResultY[s] = ymax;
            s++;
        }
        else if (y[i] <= ymax && y[j] <= ymax)
        {
            TopResultX[s] = x[i];
            TopResultY[s] = y[i];
            s++;
        }
    }
    return s;
}

int RightClip(int x[], int y[], int n)
{
    int s = 0, j;
    for (int i = 0; i < n; i++)
    {
        j = (i + 1) % (n);
        if (x[i] > xmax && x[j] <= xmax)
        {
            RightResultX[s] = xmax;
            RightResultY[s] = y[i] + (xmax - x[i]) * (y[j] - y[i]) / (x[j] - x[i]);
            s++;
        }
        else if (x[i] > xmax && x[j] > xmax)
        {
            continue;
        }
        else if (x[i] <= xmax && x[j] > xmax)
        {
            RightResultX[s] = x[i];
            RightResultY[s] = y[i];
            s++;
            RightResultX[s] = xmax;
            RightResultY[s] = y[j] + (xmax - x[j]) * (y[j] - y[i]) / (x[j] - x[i]);
            s++;
        }
        else if (x[i] <= xmax && x[j] <= xmax)
        {
            RightResultX[s] = x[i];
            RightResultY[s] = y[i];
            s++;
        }
    }
    return s;
}

int BottomClip(int x[], int y[], int n)
{
    int s = 0, j;
    for (int i = 0; i < n; i++)
    {
        j = (i + 1) % n;
        if (y[i] < ymin && y[j] >= ymin)
        {
            BottomResultX[s] = x[i] + (ymin - y[i]) * (x[j] - x[i]) / (y[j] - y[i]);
            BottomResultY[s] = ymin;
            s++;
        }
        else if (y[i] < ymin && y[j] < ymin)
        {
            continue;
        }
        else if (y[i] >= ymin && y[j] < ymin)
        {
            BottomResultX[s] = x[i];
            BottomResultY[s] = y[i];
            s++;
            BottomResultX[s] = x[j] + (ymin - y[j]) * (x[j] - x[i]) / (y[j] - y[i]);
            BottomResultY[s] = ymin;
            s++;
        }
        else if (y[i] >= ymin && y[j] >= ymin)
        {
            BottomResultX[s] = x[i];
            BottomResultY[s] = y[i];
            s++;
        }
    }
    return s;
}

void drawwindow()
{
    setcolor(YELLOW);
    line(xmin, ymin, xmax, ymin);
    line(xmax, ymin, xmax, ymax);
    line(xmax, ymax, xmin, ymax);
    line(xmin, ymax, xmin, ymin);
    setcolor(WHITE);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    int x[] = {55, 55, 15, 65, 115, 75, 75};
    int y[] = {5, 15, 15, 215, 15, 15, 5};
    int n = 7, j;
    drawwindow();
    for (int i = 0; i < n; i++)
    {
        j = (i + 1) % n;
        line(x[i], y[i], x[j], y[j]);
    }
    getch();
    cleardevice();
    drawwindow();
    int n1 = LeftClip(x, y, n);
    for (int i1 = 0; i1 < n1; i1++)
    {
        j = (i1 + 1) % n1;
        line(LeftResultX[i1], LeftResultY[i1], LeftResultX[j], LeftResultY[j]);
    }
    getch();
    cleardevice();
    drawwindow();
    int n2 = TopClip(LeftResultX, LeftResultY, n1);
    for (int i2 = 0; i2 < n2; i2++)
    {
        j = (i2 + 1) % n2;
        line(TopResultX[i2], TopResultY[i2], TopResultX[j], TopResultY[j]);
    }
    getch();
    cleardevice();
    drawwindow();
    int n3 = RightClip(TopResultX, TopResultY, n2);
    for (int i3 = 0; i3 < n3; i3++)
    {
        j = (i3 + 1) % n3;
        line(RightResultX[i3], RightResultY[i3], RightResultX[j], RightResultY[j]);
    }
    getch();
    cleardevice();
    drawwindow();
    int n4 = BottomClip(RightResultX, RightResultY, n3);
    for (int i4 = 0; i4 < n4; i4++)
    {
        j = (i4 + 1) % n4;
        line(BottomResultX[i4], BottomResultY[i4], BottomResultX[j], BottomResultY[j]);
    }
    getch();
}
