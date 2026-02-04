#include <iostream>

using namespace std;

bool isGameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void setupGame() {
	// Initialize game settings
	isGameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
void DrawGame() {
	// Render game elements
	system("cls");
	for (int i = 0; i < width; i++)
	{
		cout << "#";

	}
	cout << endl;

	for (int i = 0 ; i < height-2;i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (j == 0 )
			{
				cout << "#";
				
			}
			else if (j == width -1)
			{
				cout << "#";
				cout << endl;
			}
			else if (j < width -1)
			{
				cout << " ";
			}
			

		}
	}

	for (int i =0 ; i < width ; i++)
	{
		cout << "#";
	}
	cout << endl;
}
void InputHandler() {
	// Handle user input
}
void GameLogic() {
	// Update game state
}

int main() {
	setupGame();
	while (!isGameOver) {
		DrawGame();
		isGameOver = true; // Temporary to avoid infinite loop
		InputHandler();
		GameLogic();
	}
	return 0;
}