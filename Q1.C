//Write a Program to draw a line using DDA Algorithm.//

#include<Stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int main()
{
int gdriver=DETECT;
int gmode;
float x,y,x1,x2,y1,y2,dx,dy,steps,m,xinc,yinc,k;
int x0,y0;
clrscr();
initgraph(&gdriver,&gmode,"C:\\TurboC3\\BGI");
printf("Enter Ist end point of line");
scanf("%f",&x1);
scanf("%f",&y1);
printf("Enter 2nd end point of line");
scanf("%f",&x2);
scanf("%f",&y2);
clrscr();
dx=x2-x1;
dy=y2-y1;
if(abs(dx)>abs(dy))
{
steps=dx;
}
else
{
steps=dy;
}

xinc=dx/steps;
yinc=dy/steps;
x0=x;
y0=y;
putpixel(x0,y0,RED);
for(k=0;k<=steps;k++)
{
x=x+xinc;
y=y+yinc;
x0=x;
y0=y;
putpixel(x0,y0,RED);
}
getch();
closegraph();
return 0;
}

