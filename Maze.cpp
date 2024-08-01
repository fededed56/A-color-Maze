#include <windows.h>
#include <bits/stdc++.h>
#include<conio.h>
#include <unistd.h>
using namespace std;
#define BACKGROUND_YELLOW 0x50
#define BACKGROUND_NORMAL 0x00
int HEIGH,WIDTH;
int unmap[100][100];
int x,y;
void Draw() {
	for(int i=0;i<HEIGH-1;i++)
	{
		for(int j=0;j<WIDTH-1;j++)
		{
			unmap[i][j]=0;
		}
	}
	for ( int i=0; i<WIDTH; i++ ) {
		unmap[0][i] = 1;
		unmap[HEIGH-1][i] = 1;
	}
	for ( int i=0; i<HEIGH; i++ ) {
		unmap[i][0] = 1;
		unmap[i][WIDTH-1] = 1;
	}
	srand((unsigned)time(NULL));
	for ( int i=0; i<(HEIGH*WIDTH-13)/2; i++ ) {
		unmap[rand()%(HEIGH-1)+1][rand()%(WIDTH-1)+1] = 1;
	}
	unmap[1][1] = 2;
	unmap[HEIGH-2][WIDTH-2]=3;
	x = 1;
	y = 1;
}
void screen() {
	cout.tie(NULL);
	for(int i=0; i<HEIGH; i++) {
		for(int j=0; j<WIDTH; j++) {
			if(unmap[i][j]==1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE);
			} else if(unmap[i][j]==2) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED);
			} else if(unmap[i][j]==0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN);
			} else if(unmap[i][j]==3) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_YELLOW);
			}
			cout<<"  ";
		}
		cout<<endl;
	}
	SetConsoleCursorPosition(GetStdHandle((DWORD)-11), (COORD) {
		0
	});
}

void W() {
	if(unmap[x-1][y]!=1) {
		unmap[x][y]=0;
		x--;
		unmap[x][y]=2;
	}
	if(x==HEIGH-2&&y==WIDTH-2) {
		system("cls");
		cout<<"                                                           "<<"finish!";
		sleep(1);
		exit(0);
	}
}
void S() {

	if(unmap[x+1][y]!=1) {
		unmap[x][y]=0;
		x++;
		unmap[x][y]=2;
	}
	if(x==HEIGH-2&&y==WIDTH-2) {
		system("cls");
		cout<<"                                                           "<<"finish!";
		sleep(1);
		exit(0);
	}
}
void A() {
	if(unmap[x][y-1]!=1) {
		unmap[x][y]=0;
		y--;
		unmap[x][y]=2;
	}
	if(x==HEIGH-2&&y==WIDTH-2) {
		system("cls");
		cout<<"                                                           "<<"finish!";
		sleep(1);
		exit(0);
	}
}
void D() {

	if(unmap[x][y+1]!=1) {
		unmap[x][y]=0;
		y++;
		unmap[x][y]=2;
	}
 	if(x==HEIGH-2&&y==WIDTH-2) {
		system("cls");
		cout<<"                                                           "<<"finish!";
		sleep(1);
		exit(0);
	}
}
bool Welcome()
{
	cout<<"                                                           This is a Maze."<<endl;
	cout<<"                                                           W: to move up."<<endl;
	cout<<"                                                           A: to move left."<<endl;
	cout<<"                                                           S: to move down."<<endl;
	cout<<"                                                           D: to move right."<<endl;
	cout<<"                                                           R: to rest map."<<endl;
	cout<<"                                                           press 'e' to play the game."<<endl;
	cout<<"                                                           press 'q' to quit the game."<<endl;
	char q;
	while(q=getch())
	{
		switch(q)
		{
			case 'e':
				return true;
				break;
			case 'q':
				return false;
				break;
		}
	}
}
int main() {
	if(Welcome()==false)
	{
		cout<<"                                                           Bye."<<endl;
		exit(0);
	}else{
		goto m;
	}
	m:
	system("cls");
	cout<<"                                                           map size:"<<endl;
	cout<<"                                                           height:(<100)";
	cin>>HEIGH;
	cout<<"                                                           width:(<100)";
	cin>>WIDTH;
	system("cls");
	screen();
	char c;
	cout.tie(NULL);
	Draw();
	screen();
	while(c=getch()) {
		switch(c) {
			case 'w':
				W();
				screen();
				break;
			case 'a':
				A();
				screen();
				break;
			case 's':
				S();
				screen();
				break;
			case 'd':
				D();
				screen();
				break;
			case 'r':
				Draw();
				sleep(0.4);
				screen();
				break;
			case ' ':
				unmap[x][y]=unmap[HEIGH-2][WIDTH-2];
				system("cls");
				cout<<"                                                           "<<"finish!";
				sleep(1);
				exit(0);
		}
	}
}