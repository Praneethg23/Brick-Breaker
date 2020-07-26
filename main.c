#include <stdio.h>
#include"conio.h"
#include <math.h>
#include <graphics.h>
#include<stdlib.h>
void main()
{
    int dr,md,midx,i, midy,dx,dy,mx, my,k,x,y,xdir,ydir,oldx,oldy;
    double pi,tpi,a,t;
    void *ball;
    
    unsigned imgsize;
    dr = DETECT;
    
    initgraph(&dr, &md, “c:\\tc\\bgi”);
    midx = getmaxx()/2; midy = getmaxy()/2;
    pi = 3.14159;
    tpi = pi * 2.0;
    setcolor(13);
    circle(midx,midy,10);
    imgsize = imagesize(midx-10, midy-10, midx+10, midy+10);
    ball = malloc(imgsize);
    getimage(midx-10, midy-10, midx+10, midy+10,ball);
    putimage(midx-10, midy-10, ball,XOR_PUT);
    
    xdir = -5; ydir=5;
    
    do
    {
        oldx =  midx; oldy = midy;
        midx = midx + random();
        midy = midy + random() ;
        
        if (midx < 0)
        {
            midx = midx + 5;
            xdir =5;
        }
        if (midx > getmaxx())
        {
            midx = midx - 5;
            xdir = -5;
        }
        if (midy < 0)
        {
            midy = midy + 5;
            ydir = 5;
        }
        if (midy > getmaxy())
        {
            midy = midy - 5;
            ydir = -5;
        }
        
        putimage(midx-10, midy-10,ball,XOR_PUT);
        for (a=1.0; a<30000.0; a=a+0.1);
        {
        }
        putimage(midx-10, midy-10,ball,XOR_PUT);
        
    } while (!kbhit());
    
    getch();
}
