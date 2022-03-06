#include<iostream>
#include<graphics.h>

using namespace std;

int width, height;

void shift(int x, int y){
	putpixel(width+x, height-y, WHITE);
}

void putpixels(int x, int y, int xc, int yc){
	shift(x+xc,y+yc);
	shift(x+xc,-y+yc);
	shift(-x+xc,y+yc);
	shift(-x+xc,-y+yc);
	shift(y+xc,x+yc);
	shift(-y+xc,x+yc);
	shift(y+xc,-x+yc);
	shift(-y+xc,-x+yc);
}

void drawCircle(int r, int xc, int yc){
	int driver=DETECT, mode, x=0, y=r,d;
	initgraph(&driver,&mode,(char*)"");
	width = getwindowwidth()/2, height=getwindowheight()/2;
	line(width,0,width,height*2);
	line(0,height,width*2,height);
	putpixels(x,y,xc,yc);
	x++;
	d=3-2*r;
	while(x<=y){
		if(d<0){
			putpixels(x,y, xc, yc);
			d+=4*x+6;
		}
		else{
			y--;
			putpixels(x,y, xc, yc);
			d+=4*(x-y)+10;
		}
		x++;
	}	
	getch();
}

int main(){
	int radius, xc, yc;
	cout<<"Enter radius : ";
	cin>>radius;
	cout<<endl<<"Enter center coordinates : ";
	cin>>xc>>yc;
	drawCircle(radius, xc, yc);
	return 0;
}