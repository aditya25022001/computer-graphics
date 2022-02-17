#include<iostream>
#include<graphics.h>

using namespace std;

int main(){
	int d=DETECT, m;
	initgraph(&d,&m,(char*)"");
	line(10,10,80,10);
	line(70,10,70,100);
	line(35,55,70,55);
	arc(35,70,270,90,15);
	arc(35,77.5,90,270,7.5);
	line(35,70,63,100);
	getch();
	return 0;
}