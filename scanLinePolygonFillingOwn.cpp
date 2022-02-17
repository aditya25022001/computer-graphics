#include<iostream>
#include<graphics.h>

using namespace std;

int ymax = 0, xmax = 0, xmin = 0, ymin = 0;

void scanLine(int arr[][2], int n){
	
}

void drawPolygon(int arr[][2], int n){
	int gd = DETECT, mode;
	initgraph(&gd,&mode,(char*)"");
	int x1 = arr[0][0], y1 = arr[0][1];
	int xn = arr[n-1][0], yn = arr[n-1][1];
	for(int i=0;i<n-1;++i){
		line(arr[i][0],arr[i][1],arr[i+1][0],arr[i+1][1]);
	}		
	xmin = xmax = arr[0][0], ymin = ymax = arr[0][1];
	for(int i=0;i<n;++i){
		if(xmin>arr[i][0]){
			xmin = arr[i][0];
		}
		if(ymin>arr[i][1]){
			ymin = arr[i][1];
		}
		if(arr[i][0]>xmax){
			xmax = arr[i][0];
		}
		if(arr[i][1]>ymax){
			ymax = arr[i][1];
		}
	}
	line(xn,yn,x1,y1);
	getch();
}

int main(){
	int n;
	cout<<"Edges : ";
	cin>>n;
	cout<<"Enter Coordinates : "<<endl;
	int arr[n][2];
	for(int i=0;i<n;++i)
		cin>>arr[i][0]>>arr[i][1];
	drawPolygon(arr,n);
	return 0;
}