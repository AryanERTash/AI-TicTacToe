#include <bits/stdc++.h>

#include "board.hpp"
#include "minmax.hpp"

using namespace std;



pair<int, int> minmax(const BoardState& board, Player player) {

	WinnerStatus win = board.get_winner();
	if (win != INCOMPLETE)
		return pair<int, int>((int)win, move);

	int n = board.get_emptycell(); // n!=-1 as game is incomplete
	if (player == PLAYERX) {

		BoardState b = board; // copy constructor(first time only)

		
		
		pair<int, int> mins = minmax(board, PLAYERO, )


	}

}
