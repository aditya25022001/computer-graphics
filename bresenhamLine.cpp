#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

int width, height;

void shift(int x, int y){
	putpixel(width+x, height-y, WHITE);
}

void drawLine(int x1, int y1, int x2, int y2){
	int driver=DETECT, mode, x=x1, y=y1, dy, dx, p;
	initgraph(&driver,&mode,(char*)"");
	width = getwindowwidth()/2, height=getwindowheight()/2;
	line(width,0,width,height*2);
	line(0,height,width*2,height);
	dy=abs(y2-y1);
	dx=abs(x2-x1);
//	quad 1
	if(x2>=x1 && y2>=y1){
		if(dx>=dy){
			shift(x,y);
			x++;
			p=2*dy-dx;
			while(x<x2){
				if(p>=0){
					y++;
					shift(x,y);
					p+=2*dy-2*dx;
				}
				else{
					shift(x,y);
					p+=2*dy;	
				}
				x++;
			}
		}
		if(dy>dx){
			shift(x,y);
			y++;
			p=2*dx-dy;
			while(y<=y2){
				if(p>=0){
					x++;
					shift(x,y);
					p+=2*dx-2*dy;
				}
				else{
					shift(x,y);
					p+=2*dx;	
				}
				y++;
			}		
		}
	}
//	quad 2
	if(x2<x1 && y2>=y1){
		if(dx>=dy){
			shift(x,y);
			x--;
			p=2*dy-dx;
			while(x>x2){
				if(p>=0){
					y++;
					shift(x,y);
					p+=2*dy-2*dx;
				}
				else{
					shift(x,y);
					p+=2*dy;	
				}
				x--;
			}
		}
		if(dy>dx){
			shift(x,y);
			y++;
			p=2*dx-dy;
			while(y<=y2){
				if(p>=0){
					x--;
					shift(x,y);
					p+=2*dx-2*dy;
				}
				else{
					shift(x,y);
					p+=2*dx;	
				}
				y++;
			}		
		}
	}
//	quad 3
	if(x2<x1 && y2<y1){
		if(dx>=dy){
			shift(x,y);
			x--;
			p=2*dy-dx;
			while(x>x2){
				if(p>=0){
					y--;
					shift(x,y);
					p+=2*dy-2*dx;
				}
				else{
					shift(x,y);
					p+=2*dy;	
				}
				x--;
			}
		}
		if(dy>dx){
			shift(x,y);
			y--;
			p=2*dx-dy;
			while(y>=y2){
				if(p>=0){
					x--;
					shift(x,y);
					p+=2*dx-2*dy;
				}
				else{
					shift(x,y);
					p+=2*dx;	
				}
				y--;
			}		
		}
	}
//	quad 4
	if(x2>=x1 && y2<y1){
		if(dx>=dy){
			shift(x,y);
			x++;
			p=2*dy-dx;
			while(x<x2){
				if(p>=0){
					y--;
					shift(x,y);
					p+=2*dy-2*dx;
				}
				else{
					shift(x,y);
					p+=2*dy;	
				}
				x++;
			}
		}
		if(dy>dx){
			shift(x,y);
			y--;
			p=2*dx-dy;
			while(y>=y2){
				if(p>=0){
					x++;
					shift(x,y);
					p+=2*dx-2*dy;
				}
				else{
					shift(x,y);
					p+=2*dx;	
				}
				y--;
			}		
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