//Write a Program to draw a line using Bresenham’s Algorithm//


#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
int x,y,x1,x2,y1,y2,dx,dy,p;
int gdriver=DETECT,gmode;
clrscr();
initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
printf("Enter Ist end point of line");
scanf("%d%d",&x1,&y1);
printf("Enter 2nd end point of line");
scanf("%d%d",&x2,&y2);
clrscr();
x=x1;
y=y1;
putpixel(x,y,4);
dx=x2-x1;
dy=y2-y1;
p=2*dy-dx;
while(x<x2)
{
if(p<0)
{
x+=1;
p+=2*dy;
}
else
{
x+=1;
y+=1;
p+=2*dy-2*dx;
}
putpixel(x,y,4);
}
getch();
closegraph();
}