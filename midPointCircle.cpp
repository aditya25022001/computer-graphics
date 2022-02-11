#include<iostream>
#include<graphics.h>

using namespace std;

int shiftX(int x){
	return x+100;
}

int shiftY(int y){
	return y+100;
}

void putpixels(int x, int y){
	putpixel(shiftX(x),shiftY(y),RED);
	putpixel(shiftX(x),shiftY(-y),RED);
	putpixel(shiftX(-x),shiftY(y),RED);
	putpixel(shiftX(-x),shiftY(-y),RED);
	putpixel(shiftY(y),shiftX(x),RED);
	putpixel(shiftY(y),shiftX(-x),RED);
	putpixel(shiftY(-y),shiftX(x),RED);
	putpixel(shiftY(-y),shiftX(-x),RED);
}

void drawCircle(int r){
	int driver=DETECT, mode, x=0, y=r,d;
	initgraph(&driver,&mode,(char*)"");
	putpixel(shiftX(x),shiftY(y),RED);
	d=1-x;
	x++;
	while(x<=y){
		if(d<0){
			putpixels(x,y);
			d+=2*x+1;
		}
		else{
			y--;
			putpixels(x,y);
			d+=2*(x-y)+1;
		}
		x++;
	}	
	getch();
}

int main(){
	int radius;
	cout<<"Enter radius : ";
	cin>>radius;
	drawCircle(radius);
	return 0;
}