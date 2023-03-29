#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

void shift(int x, int y){
	putpixel(getwindowwidth()/2+x, getwindowheight()/2-y,WHITE);
}
 
int main(){
	float x,y,x1,y1,x2,y2,dx,dy,step;
	int i,gd=DETECT,gm;
	cout<<"Enter the value of x1 and y1 : ";
	cin>>x1>>y1;
	cout<<"Enter the value of x2 and y2: ";
	cin>>x2>>y2;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	if(dx>=dy){
		step=dx;
	}
	else{
		step=dy;
	}
	dx=dx/step;
	dy=dy/step;
	x=x1;
	y=y1;
	i=1;
	initgraph(&gd,&gm,(char*)"");
	line(0,getwindowheight()/2,getwindowwidth(),getwindowheight()/2);
	line(getwindowwidth()/2,0,getwindowwidth()/2,getwindowheight());
	while(i<=step){
		shift(x,y);
		x=x+dx;
		y=y+dy;
		i=i+1;
	}
	getch();
	return 0;
}