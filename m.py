#include <bits/stdc++.h>
#include "board.hpp"
#include "minmax.hpp"

using namespace std;


int main(int argc, char const* argv[])
{
	print_welcome();

	cout << "Welcome, You are O and computer is X" << endl;


	BoardState board;
	// board.set_atcell(5, PLAYERX);


	while (1)
	{
		board.print_grid();

		cout << "Enter your move: ";
		int move;
		cin >> move;

		board.set_atcell(move, PLAYERO);

		if(board.get_winner() == PLAYERO_WIN) {
			cout << "O win\n" << endl;
			break;
		}

		pair<WinnerStatus, int> next_move_pair = minmax(board);


		int comp_move = next_move_pair.second;

		board.set_atcell(comp_move, PLAYERX);

		if(board.get_winner() == PLAYERX_WIN || board.get_winner() == TIE ) {
			cout << "Comp win" << endl;
			break;
		}

	}

	return 0;
}
