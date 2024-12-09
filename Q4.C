//write a program to draw a circle using Mid-point Algorithm//

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
int gd=DETECT,gm;
int r,x,y,p,xc=320,yc=420;
clrscr();
initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
//cleardevice();
printf("enter radius");
scanf("%d",&r);
clrscr();
x=0;
y=r;
putpixel(xc+x,yc-y,1);
p=1-r;
for(x=0;x<=y;x++)
{
if(p<0)
{
y=y;
p=(p+2*x)+3;
}
else
{
y=y-1;
p=p+((2*(x-y)+5));
}
putpixel(xc+x,yc-y,1);
putpixel(xc-x,yc-y,2);
putpixel(xc+x,yc+y,3);
putpixel(xc-x,yc+y,4);
putpixel(xc+y,yc-x,5);
putpixel(xc-y,yc-x,6);
putpixel(xc+y,yc+x,7);
putpixel(xc-y,yc+x,8);
}
getch();
closegraph();
}

