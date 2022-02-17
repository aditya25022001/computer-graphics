#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

void drawLine(int x1, int y1, int x2, int y2){
	int driver=DETECT, mode, x=x1, y=y1, dy, dx, p;
	initgraph(&driver,&mode,(char*)"");
	dy=abs(y2-y1);
	dx=abs(x2-x1);
	if(dx>=dy){
		putpixel(x,y,RED);
		x++;
		p=2*dy-dx;
		while(x<x2){
			if(p>=0){
				y++;
				putpixel(x,y,RED);
				p+=2*dy-2*dx;
			}
			else{
				putpixel(x,y,RED);
				p+=2*dy;	
			}
			x++;
		}
	}
	if(dy>dx){
		putpixel(x,y,RED);
		cout<<x<<" "<<y<<endl;
		y++;
		p=2*dx-dy;
		while(y<=y2){
			if(p>=0){
				x++;
				putpixel(x,y,RED);
				cout<<x<<" "<<y<<endl;
				p+=2*dx-2*dy;
			}
			else{
				putpixel(x,y,RED);
				cout<<x<<" "<<y<<endl;
				p+=2*dx;	
			}
			y++;
		}		
	}
	getch();
}

int main(){
	int x1, y1, x2, y2;
	cout<<"Enter x1 and y1 : ";
	cin>>x1>>y1;
	cout<<endl;
	cout<<"Enter x2 and y2 : ";
	cin>>x2>>y2;
	drawLine(x1,y1,x2,y2);
	return 0;
}