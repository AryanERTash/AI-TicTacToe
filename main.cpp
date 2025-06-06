#include <bits/stdc++.h>
#include "board.hpp"
#include "minmax.hpp"

using namespace std;


int main(int argc, char const* argv[])
{
	// welcome
	print_welcome();

	cout << "Welcome, You are O and computer is X" << endl;

	BoardState board;

	int tie = 0, comp_win = 0, user_win = 0;


	while (1) {
		// ask for continuation
		cout << "\nTies: " << tie << ", Wins: " << user_win << ", Loss: " << comp_win;

		cout << "\nPress 'c' to continue or 'q' to quit: ";
		char ch;
		cin >> ch;
		if (ch == 'q' || ch == 'Q' || (ch != 'c' && ch != 'C')) break;


		cout << "\nDo you want to play first(y/n)?: "; // who will play first??
		cin >> ch;


		board.occupied = 0; // nothing is occupied in board




		if (ch == 'n') {

			//computer maks the first move

			pair<WinnerStatus, int> first_move = minmax(board);
			board.set_atcell(first_move.second, PLAYERX);	// reflex computer choice

			cout << "\nComputer played at " << first_move.second << endl;

			board.print_grid();
		}
		else if (ch != 'y')
		{

			continue;

		}


		while (1)
		{
			int usr_mv;

		mv_input:
			usr_mv = 0;
			// take input until no valid answer is recieved 
			cout << "\nEnter your move from";
			vector<int> empty_cells = board.get_all_emptycells();

			for (auto cell : empty_cells) {
				cout << " " << cell;
			}
			cout << ": ";

			if (!(cin >> usr_mv)) {
				cin.clear(); // clear error flag

				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please enter a number.\n";
				
				goto mv_input;
			}

			if (usr_mv < 1 || usr_mv > 9) {
				cout << "The move is invalid. Try another\n";
				goto mv_input;
			}


			if (board.is_occupied(usr_mv)) {
				cout << "The position " << usr_mv << " is already occupied. Try another position\n";
				goto mv_input;
			}



			board.set_atcell(usr_mv, PLAYERO);	// reflect user choice




			usleep(100000); // simulate thinking
			pair<WinnerStatus, int> comp_move = minmax(board);	// computer moves

			int move = comp_move.second;
			board.set_atcell(move, PLAYERX);

			WinnerStatus wstat = board.get_winner(); // status of board

			board.print_grid();


			if (wstat == TIE) {
				cout << "The game ended in a tie.\n";
				tie++;
			}
			else if (wstat == PLAYERO_WIN) {
				user_win++;
				cout << "Congratulations you won.\n";

			}
			else if (wstat == PLAYERX_WIN)
			{

				comp_win++;
				cout << "Computer won, better luck next time.\n";

			}

			if (wstat != INCOMPLETE) {

				cout << "\n\n";
				// new game
				break;
			}


		}

	}

	return 0;
}
