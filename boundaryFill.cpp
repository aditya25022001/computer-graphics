#include<iostream>
#include<graphics.h>

#define MAX(x,y) (x<y?y:x)
#define MIN(x,y) (x<y?x:x)

using namespace std;

int gd = DETECT, mode;

void init(){
	initgraph(&gd,&mode,(char*)"");
}

bool checkIn(int x, int y, int arr[][2], int n){
	bool inside = false;
	int counter = 0;
	double xinters;
	int x1=arr[0][0], y1=arr[0][1], x2, y2;
	for(int i=1;i<n;++i){
		x2=arr[i][0];
		y2=arr[i][1];
		if(y>MIN(y1,y2)){
			if(y=MAX(y1,y2)){
				if(x<=MAX(x1,x2)){
					if(y1!=y2){
						xinters = (y-y1)*(x2-x)/(y2-y1)+x1;
						if(x1==x2 || x<=xinters){
							counter++;
						}
					}
				}
			}
		}
		x1=x2;
		y1=y2;
	}
	if(counter%2!=0)
		inside = true;
	return inside;
}

void boundaryFill(int x, int y, int color, int bColor, int arr[][2], int n){
	cout<<checkIn(x,y,arr,n)<<endl;
	if(getpixel(x,y)!=color && getpixel(x,y)!=bColor && checkIn(x,y,arr,n)){
		putpixel(x,y,color);
		boundaryFill(x,y+1,color, bColor, arr, n);		
		boundaryFill(x,y-1,color, bColor, arr, n);		
		boundaryFill(x-1,y,color, bColor, arr, n);		
		boundaryFill(x+1,y,color, bColor, arr, n);		
		boundaryFill(x-1,y-1,color, bColor, arr, n);		
		boundaryFill(x+1,y-1,color, bColor, arr, n);		
		boundaryFill(x+1,y+1,color, bColor, arr, n);		
		boundaryFill(x+1,y-1,color, bColor, arr, n);		
	}
}

void drawPolygon(int arr[][2], int n){
	int x1 = arr[0][0], y1 = arr[0][1];
	int xn = arr[n-1][0], yn = arr[n-1][1];
	for(int i=0;i<n-1;++i){
		line(arr[i][0],arr[i][1],arr[i+1][0],arr[i+1][1]);
	}
	line(xn,yn,x1,y1);
}

int xmin=INT_MIN, ymin=INT_MIN, xmax=INT_MAX, ymax=INT_MAX;

int main(){
	int n;
	cout<<"Edges : ";
	cin>>n;
	int arr[n][2];
	for(int i=0;i<n;++i){
		cin>>arr[i][0]>>arr[i][1];
		if(arr[i][0]>xmin){
			xmin=arr[i][0];
		}
		if(arr[i][1]>ymin){
			ymin=arr[i][1];
		}
		if(arr[i][0]<xmax){
			xmax=arr[i][0];
		}
		if(arr[i][1]<ymax){
			ymax=arr[i][1];
		}
	}
	init();
	drawPolygon(arr, n);
	boundaryFill((xmin+xmax)/2,(ymin+ymax)/2,3,15,arr,n);
	getch();
	return 0;
}