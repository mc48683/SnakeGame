#include "header.hpp"

void edge::setup() {
	gameover = false;
	headx = 7;
	heady = 4;
	srand(time(NULL));
	applex = 1 + rand() % (14 - 2 + 1);
	appley = 1 + rand() % (29 - 2 + 1);
	score = 0;

}

void edge::snake_body()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if ((i == row - 1) && (j == 0))
				matrix[i][j] = dl;
			else if ((i == 0) && (j == 0))
				matrix[i][j] = ul;
			else if ((i == 0) && (j == col - 1))
				matrix[i][j] = ur;
			else if ((i == row - 1) && (j == col - 1))
				matrix[i][j] = dr;
			else if (j == col - 1)
				matrix[i][j] = vert;
			else if (i == row - 1)
				matrix[i][j] = horiz;
			else if (j == 0)
				matrix[i][j] = vert;
			else if (i == 0)
				matrix[i][j] = horiz;

			else
			{
				matrix[i][j] = ' ';
			}
			if (i == headx && j == heady)
			{
				matrix[i][j] = char(153);
			}
			else if (i == applex && j == appley)
			{
				matrix[i][j] = '@';
			}
			else
			{
				for (int k = 0; k < length; k++)
				{
					if (arr[k].x == 0 && arr[k].y == 0)
					{
						matrix[0][0] = ul;
					}
					else if (arr[k].x == i && arr[k].y == j)
					{
						matrix[i][j] = 'o';

					}
				}
			}

		}
	}
}

void edge::check_if_pressed()
{
	if (_kbhit())
	{
		char c = _getch();
		if (c == 'w')
		{
			direction = 'u';
		}
		else if (c == 'a')
		{
			direction = 'l';
		}
		else if (c == 's')
		{
			direction = 'd';
		}
		else if (c == 'd')
		{
			direction = 'r';
		}
	}
}


void edge::algorithm()
{
	int prevX = arr[0].x;
	int prevY = arr[0].y;
	int prev2X, prev2Y;
	arr[0].x = headx;
	arr[0].y = heady;
	for (int i = 1;i < length; i++)
	{
		prev2X = arr[i].x;
		prev2Y = arr[i].y;
		arr[i].x = prevX;
		arr[i].y = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	if (direction == 'u')
		headx--;
	else if (direction == 'l')
		heady--;
	else if (direction == 'd')
		headx++;
	else if (direction == 'r')
		heady++;

	for (int i = 0; i < length;i++)
	{
		if (arr[i].x == headx && arr[i].y == heady)
			gameover = true;
	}
	for (int i = 0;i < row;++i)
	{
		for (int j = 0;j < col;++j)
		{
			if ((matrix[i][j] == horiz))
			{
				if (headx == i && heady == j)
					gameover = true;
			}
			else if (matrix[i][j] == vert)
			{
				if (headx == i && heady == j)
					gameover = true;
			}
		}
	}

	if (headx == applex && heady == appley)
	{
		score += 1;
		srand(time(NULL));
		applex = 1 + rand() % (14 - 2 + 1);
		appley = 1 + rand() % (29 - 2 + 1);
		for (int k = 0; k < length; k++)
		{
			if (arr[k].x == applex && arr[k].y == appley)
			{
				applex = 1 + rand() % (14 - 2 + 1);
				appley = 1 + rand() % (29 - 2 + 1);
			}
		}

		length++;
	}
}

void edge::print()
{
	system("Color 0A");
	system("cls");
	cout << endl;
	cout << "    " << block << thb << thb << " " << block << thb << thb << bhb << " " << block << thb << thb << block << " " << block << " " << block << " " << block << thb << thb << endl;
	cout << "    " << thb << thb << block << " " << block << "  " << block << " " << block << bhb << bhb << block << " " << block << thb << bhb << " " << block << thb << thb << endl;
	cout << "    " << thb << thb << thb << " " << thb << "  " << thb << " " << thb << "  " << thb << " " << thb << " " << thb << " " << thb << thb << thb << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << "\t   Score:" << score << endl;
}