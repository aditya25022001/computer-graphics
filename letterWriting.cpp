#include<iostream>
#include<graphics.h>

using namespace std;

int main(){
	int d=DETECT, m;
	initgraph(&d,&m,(char*)"");
	line(10,24,80,24);
	line(45,73,80,140);
	line(45,24,45,38);
	arc(45,17,90,270,7);
	arc(45,48.5,90,270,10.5);
	arc(45,69.5,270,90,10.5);
	arc(45,76.5,90,270,3.5);
//	line(10,10,80,10);
//	line(70,10,70,100);
//	line(35,55,70,55);
//	arc(35,70,270,90,15);
//	arc(35,77.5,90,270,7.5);
//	line(35,70,60,100);
	getch();
	return 0;
}