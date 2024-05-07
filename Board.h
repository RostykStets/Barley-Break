#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define board_height 4
#define board_width 4

class Board
{
	int board_x;
	int board_y;
	string board[board_height][board_width];
public:
	Board();
	void RandomBoard();
	int GetX();
	int GetY();
	string GetElem(int i, int j);
	void SetX(int new_x);
	void SetY(int new_y);
	void SetElem(int i, int j, string value);
	void ShowBoard();
	Board CorrectBoard();
	bool IsCorrect();
	bool iscorrect(Board correct_board);
	bool CheckRight();
	bool CheckLeft();
	bool CheckDown();
	bool CheckUp();
	void MoveRight();
	void MoveLeft();
	void MoveDown();
	void MoveUp();
	~Board();
};