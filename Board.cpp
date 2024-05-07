#include "Board.h"

Board::Board()
{
	for (int i = 0; i < board_height; i++)
	{
		for (int j = 0; j < board_width; j++)
		{
			this->board[i][j] = " ";
		}
	}
}
Board::~Board()
{
	for (size_t i = 0; i < board_height; i++)
	{
		for (size_t j = 0; j < board_width; j++)
		{
			this->board[i][j] = "";
		}
	}
}

void Board::RandomBoard()
{
	bool correct_generation = false;
	int sum;
	int zr = 0, zero_row = 0;
	vector<int> v = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	while (correct_generation != true)
	{
		sum = 0;

		random_shuffle(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == 0)
			{
				zr = i;
				break;
			}
		}
		if (zr <= 3) zero_row = 1;
		else if (zr > 3 && zr <= 7) zero_row = 2;
		else if (zr > 7 && zr <= 11) zero_row = 3;
		else if (zr > 11 && zr <= 15) zero_row = 4;

		for (int i = 0; i < 15; i++)
		{
			int val1 = v[i];
			if(val1 != 0)
				for (int j = i + 1; j <= 15; j++)
				{
					int val2 = v[j];
					if (val1 > val2 && val2 != 0) sum++;
				}
		}
		sum += zero_row;

		if (sum % 2 == 0) correct_generation = true;
	}

	for (int i = 0; i < board_height; i++)
	{
		for (int j = 0; j < board_width; j++)
		{
			if(v.back() < 10) this->board[i][j] = " " + to_string(v.back());
			else this->board[i][j] = to_string(v.back());
			if (this->board[i][j] == " 0")
			{
				this->board[i][j] = " ";
				this->SetX(i);
				this->SetY(j);
			}
			v.pop_back();
		}
	}
}

int Board::GetX()
{
	return this->board_x;
}
int Board::GetY()
{
	return this->board_y;
}
string Board::GetElem(int i, int j)
{
	return this->board[i][j];
}

void Board::SetX(int new_x)
{
	this->board_x = new_x;
}
void Board::SetY(int new_y)
{
	this->board_y = new_y;
}
void Board::SetElem(int i, int j, string value)
{
	this->board[i][j] = value;
}

void Board::ShowBoard()
{
	for (int i = 0; i < board_height; i++)
	{
		for (int j = 0; j < board_width; j++)
		{
			cout << this->GetElem(i, j) << " ";
		}
		cout << endl;
	}
}

Board Board::CorrectBoard()
{
	Board b;

	vector<string> values = { " ","15","14","13","12","11","10"," 9"," 8"," 7"," 6"," 5"," 4"," 3"," 2"," 1"};

	for (int i = 0; i < board_height; i++)
	{
		for (int j = 0; j < board_width; j++)
		{
			b.SetElem(i, j, values.back());
			values.pop_back();
		}
	}
	return b;
}

bool Board::IsCorrect()
{
	int count = 0;
	Board b = this->CorrectBoard();
	for (int i = 0; i < board_height; i++)
	{
		for (int j = 0; j < board_width; j++)
		{
			if (this->GetElem(i, j) == b.GetElem(i, j)) count++;
		}
	}
	return count == 16;
}

bool Board::iscorrect(Board correct_board)
{
	int count = 0;
	for (int i = 0; i < board_height; i++)
		for (int j = 0; j < board_width; j++)
			if (this->GetElem(i, j) == correct_board.GetElem(i, j)) count++;
	return count == 16;
}

bool Board::CheckRight()
{
	return this->GetY() < 3;
}
bool Board::CheckLeft()
{
	return this->GetY() > 0;
}
bool Board::CheckDown()
{
	return this->GetX() < 3;
}
bool Board::CheckUp()
{
	return this->GetX() > 0;
}

void Board::MoveRight()
{
	if (this->CheckRight())
	{
		this->board[this->GetX()][this->GetY()] = this->GetElem(this->GetX(), this->GetY()+1);
		this->board[this->GetX()][this->GetY() + 1] = " ";
		if(this->GetY() != 3) this->SetY(this->GetY() + 1);
	}
}
void Board::MoveLeft()
{
	if (this->CheckLeft())
	{
		this->board[this->GetX()][this->GetY()] = this->GetElem(this->GetX(), this->GetY() - 1);
		this->board[this->GetX()][this->GetY() - 1] = " ";
		if(this->GetY() != 0) this->SetY(this->GetY() - 1);
	}
}
void Board::MoveDown()
{
	if (this->CheckDown())
	{
		this->board[this->GetX()][this->GetY()] = this->GetElem(this->GetX() + 1, this->GetY());
		this->board[this->GetX() + 1][this->GetY()] = " ";
		if (this->GetX() != 3) this->SetX(this->GetX() + 1);
	}
}
void Board::MoveUp()
{
	if (this->CheckUp())
	{
		this->board[this->GetX()][this->GetY()] = this->GetElem(this->GetX() - 1, this->GetY());
		this->board[this->GetX() - 1][this->GetY()] = " ";
		if (this->GetX() != 0) this->SetX(this->GetX() - 1);
	}
}