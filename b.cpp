#include<iostream>
#include<graphics.h>
#include<dos.h>
 
using namespace std;
 
void boundaryFill(int x,int y,int f_color,int b_color){
	if(getpixel(x,y)!=b_color && getpixel(x,y)!=f_color){
		putpixel(x,y,f_color);
		delay(300);
		boundaryFill(x+1,y,f_color,b_color);
		boundaryFill(x,y+1,f_color,b_color);
		boundaryFill(x-1,y,f_color,b_color);
		boundaryFill(x,y-1,f_color,b_color);
		boundaryFill(x+1,y+1,f_color,b_color);
		boundaryFill(x-1,y-1,f_color,b_color);
		boundaryFill(x-1,y+1,f_color,b_color);
		boundaryFill(x+1,y-1,f_color,b_color);
	}
}
 
int main(){
	int gm,gd=DETECT,radius;
	int e, xmax=INT_MIN, xmin=INT_MAX, ymax=INT_MIN, ymin=INT_MAX;
	cout<<"Enter no of edges : ";
	cin>>e;
	cout<<endl;
	int arr[e][2];
	cout<<"Enter endpoints : "<<endl;
	for(int i=0;i<e;++i){
		cin>>arr[i][0]>>arr[i][1];
		if(arr[i][0]<xmin){
			xmin=arr[i][0];
		}
		if(arr[i][1]<ymin){
			ymin=arr[i][1];
		}
		if(arr[i][0]>xmax){
			xmax=arr[i][0];
		}
		if(arr[i][1]>ymax){
			ymax=arr[i][1];
		}
	}
	initgraph(&gd,&gm,(char*)"");
	int i;
	for(i=0;i<e-1;++i){
		line(arr[i][0],arr[i][1],arr[i+1][0],arr[i+1][1]);
	}
	line(arr[i][0],arr[i][1],arr[0][0],arr[0][1]);
	boundaryFill((xmin+xmax)/2,(ymin+ymax)/2,4,15);
	getch();
	return 0;
}