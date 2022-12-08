#include "header.hpp"

int main()
{
	edge snake;
	system("Color 0A");
	cout << endl << endl << endl << endl << endl << endl << endl;
	string s = "\t\t\t\t\t     _________         _________\n"
		"\t\t\t\t\t    /         \\       /         \\\n"
		"\t\t\t\t\t   /  /~~~~~\\  \\     /  /~~~~~\\  \\\n"
		"\t\t\t\t\t   |  |     |  |     |  |     |  |\n"
		"\t\t\t\t\t   |  |     |  |     |  |     |  |\n"
		"\t\t\t\t\t   |  |     |  |     |  |     |  |         /\n"
		"\t\t\t\t\t   |  |     |  |     |  |     |  |       //\n"
		"\t\t\t\t\t  (o  o)    \\  \\_____/  /     \\  \\_____/ /\n"
		"\t\t\t\t\t   \\__/      \\         /       \\        /\n"
		"\t\t\t\t\t    |	      ~~~~~~~~~         ~~~~~~~~\n"
		"\t\t\t\t\t    ^\n";

	cout << "\t\t\t\t\t\t   S N A K E   G A M E" << endl << endl;
	cout << s << endl;
	cout << "\t\t\t\t\t\t   Press any key to play";
	char c = _getch();

	snake.setup();
	while (!snake.gameover) {

		snake.snake_body();
		snake.print();
		snake.check_if_pressed();
		snake.algorithm();
	}
	system("Color 0C");
	cout << endl;
	cout << "      G A M E   O V E R!";
	cout << endl << endl;
	return 0;

}