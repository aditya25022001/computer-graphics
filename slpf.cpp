#include<iostream>
#include<graphics.h>

using namespace std;

int ymin=INT_MAX, ymax=INT_MIN;

int main(){
	int e;
	cout<<"Enter edges : ";
	cin>>e;
	int arr[e][2];
	cout<<endl<<"Enter coordinates : "<<endl;
	for(int i=0;i<e;++i){
		cin>>arr[i][0]>>arr[i][1];
		if(arr[i][1]<ymin){
			ymin=arr[i][1];
		}
		if(arr[i][1]>ymax){
			ymax=arr[i][1];
		}
	}
	int intersections[ymax-ymin+1][2];
	int s = ymin, u;
	int j=0;
	while(s<=ymax){
		int x1,y1,x2,y2;
		for(int i=0;i<e;++i){
			x1=arr[i][0];
			y1=arr[i][1];
			x2=arr[(i+1)%e][0];
			y2=arr[(i+1)%e][1];
			cout<<x1<<" "<<y1<<", "<<x2<<" "<<y2<<endl;
			if(y1!=y2){
				u=(s-y1)/(y2-y1);
				if(u<=1 && u>=0){
					intersections[j][0]=x1+(x2-x1)*u;
					intersections[j][1]=s;
				}
			}
			else{
				intersections[j][0]=x1;
				intersections[j][1]=s;
			}
			j++;
		}
		s++;
	}
	for(int i=0;i<ymax-ymin+1;++i){
		cout<<intersections[i][0]<<" "<<intersections[i][1]<<endl;
	}
	return 0;
}