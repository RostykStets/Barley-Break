#include "Game.h"
#include "Board.h"
#include <fstream>

void Game::GameStart()
{
	srand(time(NULL));
	int symbol = 0;
	int step_count = 0;
	int min_count = 0;
	bool game_over = false;
	Board board;
	Board correct_board = Board().CorrectBoard();
	board.RandomBoard();
	int current_x = 0, current_y = 0;
	/*while (!board.IsCorrect())
	{
		cout << "Current step count: " << step_count << "\n\n";
		board.ShowBoard();
		symbol = _getch();
		if ((char)symbol == KeyRight)
		{
			current_y = board.GetY();
			board.MoveRight();
			if(board.GetY() == current_y + 1)
				step_count++;
		}
		else if ((char)symbol == KeyLeft) 
		{
			current_y = board.GetY();
			board.MoveLeft();
			if(board.GetY() == current_y - 1)
				step_count++;
		}
		else if ((char)symbol == KeyDown) 
		{
			current_x = board.GetX();
			board.MoveDown();
			if(board.GetX() == current_x + 1)
				step_count++;
		}
		else if ((char)symbol == KeyUp) 
		{
			current_x = board.GetX();
			board.MoveUp();
			if(board.GetX() == current_x + 1)
				step_count++;
		}
		else if ((char)symbol == 'q')
		{
			game_over = true;
			break;
		}

		system("cls");
	}*/

	while (!board.iscorrect(correct_board))
	{
		cout << "Current step count: " << step_count << "\n\n";
		board.ShowBoard();
		symbol = _getch();
		if ((char)symbol == Key_right || (char)symbol == Key_RIGHT)
		{
			current_y = board.GetY();
			board.MoveRight();
			if (board.GetY() == current_y + 1)
				step_count++;
		}
		else if ((char)symbol == Key_left || (char)symbol == Key_LEFT)
		{
			current_y = board.GetY();
			board.MoveLeft();
			if (board.GetY() == current_y - 1)
				step_count++;
		}
		else if ((char)symbol == Key_down || (char)symbol == Key_DOWN)
		{
			current_x = board.GetX();
			board.MoveDown();
			if (board.GetX() == current_x + 1)
				step_count++;
		}
		else if ((char)symbol == Key_up || (char)symbol == Key_UP)
		{
			current_x = board.GetX();
			board.MoveUp();
			if (board.GetX() == current_x + 1)
				step_count++;
		}
		//else if ((char)symbol == 'q')
		else if ((char)symbol == Game_quit || (char)symbol == GAME_QUIT)
		{
			game_over = true;
			break;
		}

		system("cls");
	}

	cout << "Step count: " << step_count << "\n\n";

	if(!game_over) board.ShowBoard();
	
	ifstream input;
	input.open("Step counts.txt");
	ofstream output;
	output.open("Step counts.txt", ios::app);
	int step;

	if (game_over) cout << "\n\nGAME OVER!!" << endl;
	else cout << "\n\nCONGRATULATIONS!!\n\n";

	if(!game_over)
	{
		{
			vector<int> steps;
			bool is_empty = input.peek() == input.eof();

			if (!is_empty)
				while (input >> step)
					steps.push_back(step);

			if (steps.empty()) min_count = step_count;
			else
			{
				min_count = *min_element(steps.begin(), steps.end());
				if (step_count < min_count)
				{
					min_count = step_count;
					cout << "New min step count: " << min_count << "\n\n";
				}
			}
			output << "\n" << step_count;
		}

		cout << "Steps: " << step_count << "\n\n" << "Min steps: " << min_count << "\n\n";
	}

	board.~Board();

	input.close();
	output.close();
}