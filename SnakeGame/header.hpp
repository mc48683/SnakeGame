#include <iostream>
#include <time.h>
#include <string>
#include <conio.h>
#include <windows.h>

typedef struct
{
	int x, y;
}snake;

using namespace std;
class edge
{
public:
	int col = 30;
	int row = 15;
	int headx, heady, applex, appley;
	int score;
	snake arr[100];
	int length;
	char direction;
	char** matrix;
	bool gameover;
	char vert = (char)186;
	char horiz = (char)205;
	char ul = (char)201;
	char ur = (char)187;
	char dl = (char)200;
	char dr = (char)188;
	char block = (char)219;
	char space = (char)176;
	char thb = (char)223;
	char bhb = (char)220;
	edge()
	{
		matrix = new char* [row];
		for (int i = 0;i < row;++i)
		{
			matrix[i] = new char[col];
		}
	}

	void print();
	void setup();
	void snake_body();
	void check_if_pressed();
	void algorithm();
};

